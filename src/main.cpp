#ifndef UNITTEST

#include <vector>
#include <chrono>
#include <iostream>
#include <string>
#include <uvw.hpp>

const char* BIND_ADDRESS = "0.0.0.0";
const unsigned int PORT = 10080;

const char* RESPONSE =
  "HTTP/1.0 200 OK\r\n"
  "Connection: Close\r\n"
  "Content-type: text/html; charset=utf-8\r\n"
  "Content-length: 14\r\n"
  "\r\n"
  "Hello world!\r\n"
  ;

void listen(uvw::Loop &loop) {
  std::shared_ptr<uvw::TCPHandle> tcp = loop.resource<uvw::TCPHandle>();

  tcp->on<uvw::ErrorEvent>([](const uvw::ErrorEvent &e, uvw::TCPHandle &) {
    std::cerr << "Error on accepting socket: " << e.what() << std::endl;
  });
  tcp->on<uvw::ListenEvent>([](const uvw::ListenEvent &, uvw::TCPHandle &srv) {
    std::shared_ptr<uvw::TCPHandle> client = srv.loop().resource<uvw::TCPHandle>();

    client->on<uvw::EndEvent>([](
      const uvw::EndEvent &,
      uvw::TCPHandle &client
    ) {
      client.close();
    });

    std::string writingBuffer = RESPONSE;
    srv.accept(*client);
    client->read();
    client->write(&writingBuffer[0], writingBuffer.size());
    client->close();
  });

  tcp->bind(BIND_ADDRESS, PORT);
  tcp->listen();
}

int main(int argc, char **argv) {
  std::cout << "=== http server started ===" << std::endl;

  auto loop = uvw::Loop::getDefault();
  listen(*loop);
  loop->run();

  std::cout << "=== http server stopped ===" << std::endl;
  return 0;
}

#else /** UNITTEST */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#endif /** UNITTEST */

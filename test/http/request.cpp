#include "doctest.h"

#include "../../src/http/request.hpp"

#include <string>

TEST_CASE("End of http header detection") {
  CHECK(http::hasEndOfHeader("GET / HTTP/1.0") == false);
  CHECK(http::hasEndOfHeader("GET / HTTP/1.0\r\n") == false);
  CHECK(http::hasEndOfHeader("GET / HTTP/1.0\r\nAccept: text/html") == false);
  CHECK(http::hasEndOfHeader("GET / HTTP/1.0\r\nAccept: text/html\r\n") == false);

  CHECK(http::hasEndOfHeader("\r\n\r\n") == true);
  CHECK(http::hasEndOfHeader("GET / HTTP/1.0\r\n\r\n") == true);
  CHECK(http::hasEndOfHeader("GET / HTTP/1.0\r\nAccept: text/html\r\n\r\n") == true);
}

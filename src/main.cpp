#ifndef UNITTEST

#include <chrono>
#include <iostream>
#include <string>
#include <uvw.hpp>

int main(int argc, char **argv) {
  std::cout << "Hello world!" << std::endl;
  return 0;
}

#else /** UNITTEST */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#endif /** UNITTEST */

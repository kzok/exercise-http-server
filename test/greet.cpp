#include "doctest.h"

#include "../src/greet.hpp"

#include <string>

TEST_CASE("greet()") {
  CHECK(greet("world") == "Hello, world!");
}

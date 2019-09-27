#ifndef GREET_HPP_INCLUDED
#define GREET_HPP_INCLUDED

#include <string>

/**
 * @param name Target name to greet
 * @return Greeting message
 */
std::string greet(const std::string& name) {
  std::string message = "Hello, ";
  message = message + name;
  message = message + "!";
  return message;
}

#endif

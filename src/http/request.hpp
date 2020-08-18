#ifndef HTTP_REQUEST_HPP_INCLUDED
#define HTTP_REQUEST_HPP_INCLUDED

#include "const.hpp"

#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace http {

struct Request {
  Version version;
  Method method;
  std::string pathname;
  std::unordered_map<std::string, std::string> headers;
};

struct ParseRequestHeaderResult {
  size_t bytesRead;
  Request result;
};

bool hasEndOfHeader(const std::string_view& input);

}  // namespace http

#endif

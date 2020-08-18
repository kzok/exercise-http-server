#include "request.hpp"

namespace http {

static std::string_view END_OF_HEADER = "\r\n\r\n";

bool hasEndOfHeader(const std::string_view& input) {
  const auto result = input.find(END_OF_HEADER);
  return result != std::string::npos;
}

}  // namespace http

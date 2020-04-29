#include "exception.hpp"

namespace cousar {

Exception::Exception(const std::string& error) : m_error(error) {}

const char* Exception::what() const noexcept { return m_error.c_str(); }

}  // namespace cousar
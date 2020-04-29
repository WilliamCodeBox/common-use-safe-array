#if !defined(COUSAR_EXCEPTION_H)
#define COUSAR_EXCEPTION_H

#include <exception>
#include <string>

namespace cousar {
class Exception : public std::exception {
 public:
  Exception(const std::string& error);
  const char* what() const noexcept;

 private:
  std::string m_error;
};
}  // namespace cousar

#endif  // COUSAR_EXCEPTION_H

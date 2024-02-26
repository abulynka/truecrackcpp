#ifndef TRUECRACK_SRC_MAIN_UTILS_UTILS_H_
#define TRUECRACK_SRC_MAIN_UTILS_UTILS_H_

#include <string>
#include <vector>
#include <sstream>
#include <ranges>
#include <iostream>

namespace utils {

class Strings {
 public:
  static inline char eol = '\n';
  [[nodiscard]] static std::vector<std::string> split(char separator, const std::string& string);
  [[nodiscard]] static std::string join(const std::string& separator, const std::vector<std::string>& array);
};

} // string

#endif //TRUECRACK_SRC_MAIN_UTILS_UTILS_H_

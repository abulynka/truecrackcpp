#ifndef TRUECRACKCPP_SRC_UTILS_SYSTEM_FILE_H_
#define TRUECRACKCPP_SRC_UTILS_SYSTEM_FILE_H_

#include <string>
#include <filesystem>
#include <vector>

#include "strings.h"
#include "base/base.h"

namespace utils {

class File {
 public:
  static bool Exists(const std::string& file_path);
  static ReturnResult Read(const std::string& file_path, uint32_t start, uint32_t length, std::vector<uint8_t>& buffer);
};

} // sys

#endif //TRUECRACKCPP_SRC_UTILS_SYSTEM_FILE_H_

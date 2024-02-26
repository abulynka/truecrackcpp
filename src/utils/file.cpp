#include "file.h"
#include "base/base.h"

#include <fstream>

namespace utils {

bool File::Exists(const std::string& file_path) {
  return std::filesystem::exists(file_path);
}

ReturnResult File::Read(const std::string& file_path, uint32_t start, uint32_t length, std::vector<uint8_t>& buffer) {
  std::ifstream file(file_path, std::ios::binary);

  if (!file.is_open()) {
    return AddSystemErrorResult("Failed to open file: " + file_path);
  }

  file.seekg(start);

  buffer.resize(length);
  file.read(reinterpret_cast<char*>(buffer.data()), length);

  file.close();

  return AddSuccess();
}

} // namespace utils
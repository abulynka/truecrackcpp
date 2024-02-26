#ifndef TRUECRACKCPP_SRC_BASE_BASECLASSERRORLOG_H_
#define TRUECRACKCPP_SRC_BASE_BASECLASSERRORLOG_H_

#include <string>

#include "utils/strings.h"
#include "utils/strings.h"
#include "utils/path_resolver.h"

namespace base {

class ErrorLog {
 public:
  ErrorLog(std::string file_name,
           int file_line,
           std::string function_name):
           file_line_(file_line),
           function_name_(std::move(function_name)) {
    file_name_ = ParseFileName(std::move(file_name));
  };

  [[nodiscard]] const std::string& get_file_name() const { return file_name_; }
  [[nodiscard]] int get_file_line() const { return file_line_; }
  [[nodiscard]] const std::string& get_function_name() const { return function_name_; }

 private:
  std::string file_name_;
  int file_line_;
  std::string function_name_;

  static std::string ParseFileName(std::string file_path) {
    const std::string document_root = utils::PathResolver::DocumentRoot();
    if (file_path.size() + 1 > document_root.size() + 1) {
      return file_path.substr(document_root.size() + 1);
    }
    return file_path;
  }
};

}

#endif //TRUECRACKCPP_SRC_BASE_BASECLASSERRORLOG_H_

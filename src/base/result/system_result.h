//
// Created by alexander on 4.1.24.
//

#ifndef TRUECRACKCPP_SRC_BASE_SYSTEM_RESULT_H_
#define TRUECRACKCPP_SRC_BASE_SYSTEM_RESULT_H_

#include <string>
#include <vector>

#include "error_log.h"
#include "utils/strings.h"

namespace base {

class SystemResult {
 public:
  SystemResult(std::string error_message, std::vector<ErrorLog> error_stack):
    error_message_(std::move(error_message)),
    error_stack_(std::move(error_stack)) {}

  void AddErrorLog(ErrorLog error_log) {
    error_stack_.push_back(std::move(error_log));
  }

  [[nodiscard]] const std::string& get_error_message() {
    return error_message_;
  }

  [[nodiscard]] std::string generateErrorMessageWithErrorStack() {
    std::string delimiter = "----------";
    std::string eol = {utils::Strings::eol};
    std::string result = std::string("----------") + eol;
    int counter = 0;
    for (const auto& error_log: error_stack_) {
      result += "[" + std::to_string(counter++) + "] "
          + error_log.get_file_name()
          + "(" + std::to_string(error_log.get_file_line()) + "): "
          + error_log.get_function_name() + "()" + utils::Strings::eol;
    }
    result += error_message_ + eol + delimiter;
    return result;
  }

 private:
  std::string error_message_;
  std::vector<ErrorLog> error_stack_;
};

}

#endif //TRUECRACKCPP_SRC_BASE_SYSTEM_RESULT_H_

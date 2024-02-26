//
// Created by alexander on 13.12.23.
//

#ifndef TRUECRACKCPP_SRC_UTILS_SYSTEM_RESULT_STATUS_H_
#define TRUECRACKCPP_SRC_UTILS_SYSTEM_RESULT_STATUS_H_

#include <string>
#include <memory>
#include <utility>

namespace base {

class UserResult {
 public:
  explicit UserResult(bool is_success, std::string message = ""):
      is_success_{is_success},
      message_{std::move(message)} {};

  [[nodiscard]] bool isSuccess() const {
    return is_success_;
  }

  [[nodiscard]] const std::string& get_message() const {
    return message_;
  }

 private:
  bool is_success_;
  std::string message_;
};

}

#endif //TRUECRACKCPP_SRC_UTILS_SYSTEM_RESULT_STATUS_H_

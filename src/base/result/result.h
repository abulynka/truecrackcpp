#ifndef TRUECRACKCPP_SRC_BASE_RESULT_H_
#define TRUECRACKCPP_SRC_BASE_RESULT_H_

#include <memory>

#include "base/result/user_result.h"
#include "base/result/system_result.h"

namespace base {

class Result {
 public:
  void set_user_result(std::unique_ptr<base::UserResult> user_result) {
    user_result_ = std::move(user_result);
  }
  [[nodiscard]] const std::unique_ptr<base::UserResult>& get_user_result() {
    return user_result_;
  }
  [[nodiscard]] bool isUserResult() {
    return user_result_ != nullptr;
  }

  void set_system_result(std::unique_ptr<base::SystemResult> system_result) {
    system_result_ = std::move(system_result);
  }
  [[nodiscard]] const std::unique_ptr<base::SystemResult>& get_system_result() {
    return system_result_;
  }
  [[nodiscard]] bool isSystemResult() {
    return system_result_ != nullptr;
  }

  [[nodiscard]] bool isError() {
    if (isSystemResult()) {
      return true;
    }
    return !user_result_->isSuccess();
  }

 private:
  std::unique_ptr<base::UserResult> user_result_;
  std::unique_ptr<base::SystemResult> system_result_;
};

} // base

#endif //TRUECRACKCPP_SRC_BASE_RESULT_H_

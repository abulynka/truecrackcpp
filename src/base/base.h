#ifndef TRUECRACKCPP_SRC_BASE_BASECLASS_H_
#define TRUECRACKCPP_SRC_BASE_BASECLASS_H_

#include <string>
#include <vector>
#include <memory>

#include "base/result/result.h"
#include "base/result/user_result.h"
#include "base/result/error_log.h"

typedef std::unique_ptr<base::Result> ReturnResult;

namespace base {

class Base {
 public:
  virtual ~Base() = default;

  static std::unique_ptr<base::Result> AddSuccess() {
    return AddUserSuccess();
  }

  static std::unique_ptr<base::Result> AddSystemSuccess() {
    return AddUserSuccess();
  }

  static std::unique_ptr<base::Result> AddUserSuccess() {
    std::unique_ptr<base::Result> result = std::make_unique<base::Result>();
    result->set_user_result(std::make_unique<base::UserResult>(true));
    return result;
  }

  static std::unique_ptr<base::Result> AddUserSuccessResult(std::string message) {
    std::unique_ptr<base::Result> result = std::make_unique<base::Result>();
    result->set_user_result(std::make_unique<base::UserResult>(true, std::move(message)));
    return result;
  }

  static std::unique_ptr<base::Result> AddUserError() {
    std::unique_ptr<base::Result> result = std::make_unique<base::Result>();
    result->set_user_result(std::make_unique<base::UserResult>(false));
    return result;
  }

  static std::unique_ptr<base::Result> AddUserErrorResult(std::string message) {
    std::unique_ptr<base::Result> result = std::make_unique<base::Result>();
    result->set_user_result(std::make_unique<base::UserResult>(false, std::move(message)));
    return result;
  }

  static std::unique_ptr<base::Result> AddSystemErrorResult(
      std::string file_name,
      int file_line,
      std::string function_name,
      std::string message) {
    std::unique_ptr<base::Result> result = std::make_unique<base::Result>();
    std::vector<ErrorLog> error_log;
    error_log.emplace_back(std::move(file_name), file_line, std::move(function_name));

    result->set_system_result(std::make_unique<base::SystemResult>(std::move(message), std::move(error_log)));
    return result;
  }

  static std::unique_ptr<base::Result> AddErrorNext(
      std::string file_name,
      int file_line,
      std::string function_name,
      std::unique_ptr<base::Result> result) {
    if (result->isSystemResult()) {
      result->get_system_result()->AddErrorLog(ErrorLog(std::move(file_name), file_line, std::move(function_name)));
    }
    return result;
  }
};

}

#define AddSuccess() base::Base::AddSuccess()

#define AddUserSuccess() base::Base::AddUserSuccess()
#define AddUserSuccessResult(message) base::Base::AddUserSuccessResult(message)
#define AddUserError() base::Base::AddUserError()
#define AddUserErrorResult(message) base::Base::AddUserErrorResult(message)

#define AddSystemSuccess() base::Base::AddSystemSuccess()
#define AddSystemError() base::Base::AddSystemErrorResult(__FILE__, __LINE__, __FUNCTION__, "")
#define AddSystemErrorResult(message) base::Base::AddSystemErrorResult(__FILE__, __LINE__, __FUNCTION__, message)

#define AddErrorNext(result) base::Base::AddErrorNext(__FILE__, __LINE__, __FUNCTION__, std::move(result))

#endif //TRUECRACKCPP_SRC_BASE_BASECLASS_H_

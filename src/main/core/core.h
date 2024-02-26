#ifndef TRUECRACKCPP_SRC_MAIN_MAIN_CORE_H_
#define TRUECRACKCPP_SRC_MAIN_MAIN_CORE_H_

#include <memory>
#include <optional>

#include "main/config/config.h"
#include "base/result/user_result.h"
#include "base/base.h"

namespace core {

class Core: public base::Base {
 public:
  Core() = delete;
  explicit Core(std::shared_ptr<config::Config> config):
    config_(std::move(config)) {}

  [[nodiscard]] ReturnResult Process();

 private:
  std::shared_ptr<config::Config> config_;

  [[nodiscard]] ReturnResult Init();
};

} // core

#endif //TRUECRACKCPP_SRC_MAIN_MAIN_CORE_H_

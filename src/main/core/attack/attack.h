#ifndef TRUECRACKCPP_SRC_MAIN_CORE_ATTACK_H_
#define TRUECRACKCPP_SRC_MAIN_CORE_ATTACK_H_

#include <memory>

#include "main/config/config.h"
#include "base/base.h"
#include "base/result/result.h"

namespace core::attack {

class Attack {
 public:
  void set_config(std::shared_ptr<config::Config> config) {
    config_ = std::move(config);
  };

  virtual std::unique_ptr<base::Result> Init() = 0;
  virtual std::unique_ptr<base::Result> Process() = 0;
  virtual std::unique_ptr<base::Result> CheckConfig() = 0;
  virtual ~Attack() = default;

 protected:
  std::shared_ptr<config::Config> config_;
};

} // core

#endif //TRUECRACKCPP_SRC_MAIN_CORE_ATTACK_H_

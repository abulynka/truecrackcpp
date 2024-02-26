#ifndef TRUECRACKCPP_SRC_MAIN_CORE_ATTACK_ATTACK_CHARSET_H_
#define TRUECRACKCPP_SRC_MAIN_CORE_ATTACK_ATTACK_CHARSET_H_

#include <memory>

#include "main/core/attack/attack.h"
#include "base/base.h"
#include "base/result/result.h"

namespace core::attack {

class AttackCharset: public Attack {
 public:
  std::unique_ptr<base::Result> Init() override {
    return AddUserSuccess();
  }

  std::unique_ptr<base::Result> Process() override;
  std::unique_ptr<base::Result> CheckConfig() override;
};

}

#endif //TRUECRACKCPP_SRC_MAIN_CORE_ATTACK_ATTACK_CHARSET_H_

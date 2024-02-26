#ifndef TRUECRACKCPP_SRC_MAIN_CORE_ATTACK_ATTACK_DICTIONARY_H_
#define TRUECRACKCPP_SRC_MAIN_CORE_ATTACK_ATTACK_DICTIONARY_H_

#include <memory>
#include "main/config/config.h"
#include "base/base.h"
#include "base/result/result.h"
#include "main/core/attack/attack.h"
#include "utils/file.h"

namespace core::attack {

class AttackDictionary: public Attack {
 public:
  std::unique_ptr<base::Result> Init() override {
    return AddUserSuccess();
  }
  std::unique_ptr<base::Result> Process() override {
    return AddUserSuccess();
  }
  std::unique_ptr<base::Result> CheckConfig() override {
    if (config_->get_words_path().empty()) {
      return AddUserErrorResult("words list can't be empty in dictionary mode");
    }

    if (!utils::File::Exists(config_->get_words_path())) {
      return AddUserErrorResult("words list file not found in dictionary mode");
    }

    return AddUserSuccess();
  };
};

}

#endif //TRUECRACKCPP_SRC_MAIN_CORE_ATTACK_ATTACK_DICTIONARY_H_

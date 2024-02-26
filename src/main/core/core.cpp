#include "core.h"

#include "utils/file.h"
#include "main/core/attack/attack.h"
#include "main/core/attack/charset/attack_charset.h"
#include "main/core/attack/dictionary/attack_dictionary.h"
#include "base/base.h"

namespace core {

ReturnResult Core::Process() {
  auto result = Init();
  if (result->isError()) {
    return AddErrorNext(result);
  }

  std::unique_ptr<core::attack::Attack> attack;
  switch (config_->get_attack_type()) {
    case config::Config::AttackType::kCharset:
      attack = std::make_unique<core::attack::AttackCharset>();
      break;

    case config::Config::AttackType::kDictionary:
      attack = std::make_unique<core::attack::AttackDictionary>();
      break;

    default:
      return AddUserErrorResult("attack type can't be empty");
  }

  attack->set_config(config_);
  auto init_result = attack->Init();
  if (init_result->isError()) {
    return AddErrorNext(init_result);
  }
  auto check_config_result = attack->CheckConfig();
  if (check_config_result->isError()) {
    return AddErrorNext(check_config_result);
  }

  return attack->Process();
}

std::unique_ptr<base::Result> Core::Init() {
//  if (config_->get_volume_path().empty()) {
//    return AddUserErrorResult("volume path can not be empty");
//  }
//
//  if (!utils::File::exists(config_->get_volume_path())) {
//    return AddUserErrorResult("volume file does not exist: " + config_->get_volume_path());
//  }

  return AddUserSuccess();
}

}
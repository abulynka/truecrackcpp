#include <memory>

#include "attack_charset.h"
#include "base/log/logging.h"
#include "base/result/result.h"
#include "main/core/decrypt_task.h"
#include "main/core/crypto_utils.h"
#include "main/core/encryption_algorithm.h"
#include "permutation/permutation.h"
#include "permutation/permutation_without_repeat.h"
#include "permutation/permutation_with_repeat.h"

namespace core::attack {

std::unique_ptr<base::Result> AttackCharset::CheckConfig() {
  if (config_->get_charset().empty()) {
    return AddUserErrorResult("charset list can't be empty in attack mode");
  }

  if (config_->get_charset().empty()) {
    return AddUserErrorResult("charset list can't be empty in attack mode");
  }

  if (config_->get_max_length() <= 0) {
    return AddUserErrorResult("max length can't be empty in attack mode");
  }

  if (config_->get_min_length() <= 0) {
    return AddUserErrorResult("min length can't be empty in attack mode");
  }

  if (config_->get_min_length() > config_->get_max_length()) {
    return AddUserErrorResult("min length can't be less than max length");
  }

  if (config_->get_restore() < 0) {
    return AddUserErrorResult("restore param can't be less than zero");
  }

  return AddUserSuccess();
}

std::unique_ptr<base::Result> AttackCharset::Process() {
  log3 << "Count\tPassword\tResult";

  std::unique_ptr<Permutation> permutation;
  if (config_->get_repetition() == config::Config::CharsetRepetition::YES) {
    permutation = std::make_unique<PermutationWithoutRepeat>();
  } else {
    permutation = std::make_unique<PermutationWithRepeat>();
  }

  std::string charset = config_->get_charset();
  uint32_t min_length = config_->get_min_length();
  uint32_t max_length = config_->get_max_length();

//  uint64_t restore = config_->get_restore();
//  uint64_t max_combinations = permutation->getMaxNumberOfCombinations(charset.size(), min_length, max_length);
  // todo: implement restore

  std::vector<config::Config::EncryptionAlgorithm> encryption_algorithms = config_->get_encryption_algorithms();
  std::vector<config::Config::KeyDerivationFunction> key_derivation_functions = config_->get_key_derivation_functions();
  std::vector<config::Config::EncryptionMode> encryption_modes = config_->get_encryption_modes();

  for (uint32_t length = min_length; length <= max_length; ++length) {
    uint64_t number_of_combinations = permutation->getMaxNumberOfCombinations(charset.size(), length);
    for (uint64_t number = 0; number < number_of_combinations; ++number) {
      std::string word = config_->get_prefix() + permutation->getCombination(charset, length, number);

      for (const auto& encryption_algorithm : encryption_algorithms) {
        for (const auto& key_derivation_function: key_derivation_functions) {
          for (const auto& encryption_mode: encryption_modes) {

            crypto::DecryptTask task(
                crypto::EncryptionAlgorithm::getEncryption(encryption_algorithm, encryption_mode, key_derivation_function),
                config_->get_encrypted_header(),
                word);

            auto decrypt = std::make_unique<crypto::CryptoUtils>();
            auto result = decrypt->Decrypt(task);

            if (result->isError()) {
              return AddErrorNext(result);
            }

            if (result->isUserResult() && result->get_user_result()->isSuccess()) {

               return AddUserSuccessResult("found password: " + word);
            }

          }
        }
      }

    }
  }

  return AddUserErrorResult("password not found");
}
}

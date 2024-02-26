#ifndef TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_ENCRYPTION_ALGORITHM_H_
#define TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_ENCRYPTION_ALGORITHM_H_

#include <memory>
#include <vector>

#include "encryption_settings.h"
#include "encryption_mode.h"
#include "encryption.h"
#include "encryption/aes.h"
#include "encryption/serpent.h"
#include "encryption/twofish.h"
#include "encryption_mode/encryption_mode_cbc.h"
#include "encryption_mode/encryption_mode_lrw.h"
#include "encryption_mode/encryption_mode_xts.h"
#include "hash.h"
#include "hash/ripemd160.h"
#include "hash/sha512.h"
#include "hash/whirpool.h"

#include "main/config/config.h"

namespace crypto {

class EncryptionAlgorithm {
 public:
  static std::shared_ptr<EncryptionSettings> getEncryption(
      config::Config::EncryptionAlgorithm algorithm,
      config::Config::EncryptionMode mode,
      config::Config::KeyDerivationFunction key_derivation_function) {

    std::shared_ptr<EncryptionSettings> encryption_settings = std::make_unique<EncryptionSettings>();
    processEncryptionAlgorithm(encryption_settings, algorithm);
    processEncryptionMode(encryption_settings, mode);
    processKeyDerivationFunction(encryption_settings, key_derivation_function);
    return encryption_settings;
  }

  static std::vector<std::shared_ptr<Encryption>> GetAvailableAlgorithms() {
    std::vector<std::shared_ptr<Encryption>> algorithms = {
        std::make_unique<AES>(),
        std::make_unique<Serpent>(),
        std::make_unique<Twofish>(),
    };

    return algorithms;
  }

 private:
  static void processEncryptionAlgorithm(const std::shared_ptr<EncryptionSettings>& encryption_settings, config::Config::EncryptionAlgorithm algorithm) {
    std::vector<std::shared_ptr<Encryption>> algorithms;

    switch (algorithm) {
      case config::Config::EncryptionAlgorithm::AES:
        algorithms.push_back(std::make_unique<AES>());
        break;

      case config::Config::EncryptionAlgorithm::SERPENT:
        algorithms.push_back(std::make_unique<Serpent>());
        break;

      case config::Config::EncryptionAlgorithm::TWOFISH:
        algorithms.push_back(std::make_unique<Twofish>());
        break;

      case config::Config::EncryptionAlgorithm::AES_TWOFISH:
        algorithms.push_back(std::make_unique<Twofish>());
        algorithms.push_back(std::make_unique<AES>());
        break;

      case config::Config::EncryptionAlgorithm::AES_TWOFISH_SERPENT:
        algorithms.push_back(std::make_unique<Serpent>());
        algorithms.push_back(std::make_unique<Twofish>());
        algorithms.push_back(std::make_unique<AES>());
        break;

      case config::Config::EncryptionAlgorithm::SERPENT_AES:
        algorithms.push_back(std::make_unique<AES>());
        algorithms.push_back(std::make_unique<Serpent>());
        break;

      case config::Config::EncryptionAlgorithm::SERPENT_TWOFISH_AES:
        algorithms.push_back(std::make_unique<AES>());
        algorithms.push_back(std::make_unique<Twofish>());
        algorithms.push_back(std::make_unique<Serpent>());
        break;

      case config::Config::EncryptionAlgorithm::TWOFISH_SERPENT:
        algorithms.push_back(std::make_unique<Serpent>());
        algorithms.push_back(std::make_unique<Twofish>());
        break;
    }

    encryption_settings->set_algorithms(std::move(algorithms));
  }

  static void processEncryptionMode(const std::shared_ptr<EncryptionSettings>& encryption_settings, config::Config::EncryptionMode mode) {
    std::shared_ptr<EncryptionMode> encryption_mode;
    switch (mode) {
      case config::Config::EncryptionMode::CBC:
        encryption_mode = std::make_shared<EncryptionModeCBC>();
        break;

      case config::Config::EncryptionMode::LRW:
        encryption_mode = std::make_shared<EncryptionModeLRW>();
        break;

      case config::Config::EncryptionMode::XTS:
        encryption_mode = std::make_shared<EncryptionModeXTS>();
        break;
    }

    encryption_settings->set_mode(std::move(encryption_mode));
  }

  static void processKeyDerivationFunction(const std::shared_ptr<EncryptionSettings>& encryption_settings, config::Config::KeyDerivationFunction key_derivation_function) {
    std::shared_ptr<Hash> hash;
    switch (key_derivation_function) {
      case config::Config::KeyDerivationFunction::WHIRLPOOL:
        hash = std::make_shared<Whirpool>();
        break;

      case config::Config::KeyDerivationFunction::SHA512:
        hash = std::make_shared<Sha512>();
        break;

      case config::Config::KeyDerivationFunction::RIPEMD160:
        hash = std::make_shared<Ripemd160>();
        break;
    }

    encryption_settings->set_hash(std::move(hash));
  }
};

}

#endif //TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_ENCRYPTION_ALGORITHM_H_

#ifndef TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_ENCRYPTION_SETTINGS_H_
#define TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_ENCRYPTION_SETTINGS_H_

#include <memory>
#include <vector>

#include "encryption.h"
#include "encryption_mode.h"
#include "hash.h"

namespace crypto {

class EncryptionSettings {
 public:
  void set_algorithms(std::vector<std::shared_ptr<Encryption>> algorithms) {
    algorithms_ = std::move(algorithms);
  }
  [[nodiscard]] const std::vector<std::shared_ptr<Encryption>>& get_algorithms() {
    return algorithms_;
  }

  void set_mode(std::shared_ptr<EncryptionMode> mode) {
    mode_ = std::move(mode);
  }
  [[nodiscard]] const std::shared_ptr<EncryptionMode>& get_modes() {
    return mode_;
  }

  void set_hash(std::shared_ptr<Hash> hash) {
    hash_ = std::move(hash);
  }
  [[nodiscard]] const std::shared_ptr<Hash>& get_hash() {
    return hash_;
  }

 private:
  std::vector<std::shared_ptr<Encryption>> algorithms_;
  std::shared_ptr<EncryptionMode> mode_;
  std::shared_ptr<Hash> hash_;
};

}

#endif //TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_ENCRYPTION_SETTINGS_H_

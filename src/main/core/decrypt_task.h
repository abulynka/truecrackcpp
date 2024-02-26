#ifndef TRUECRACKCPP_SRC_MAIN_CORE_CRYPT_DECRYPT_TASK_H_
#define TRUECRACKCPP_SRC_MAIN_CORE_CRYPT_DECRYPT_TASK_H_

#include <memory>
#include <string>
#include <vector>

#include "main/config/config.h"
#include "main/core/encryption_settings.h"

namespace crypto {

class DecryptTask {
 public:
  DecryptTask(
      std::shared_ptr<EncryptionSettings> encryption_settings,
      std::vector<uint8_t> encryptedHeader,
      std::string password
    ):
    encryption_settings_(std::move(encryption_settings)),
    encryptedHeader_(std::move(encryptedHeader)),
    password_(std::move(password)) {}

  [[nodiscard]] const std::string& get_password() const {
    return password_;
  }

  [[nodiscard]] const std::vector<uint8_t>& get_header() const {
    return encryptedHeader_;
  }

  [[nodiscard]] const std::shared_ptr<EncryptionSettings>& get_encryption_settings() const {
    return encryption_settings_;
  }

 private:
  std::shared_ptr<EncryptionSettings> encryption_settings_;
  const std::vector<uint8_t> encryptedHeader_;
  const std::string password_;
};

}

#endif //TRUECRACKCPP_SRC_MAIN_CORE_CRYPT_DECRYPT_TASK_H_

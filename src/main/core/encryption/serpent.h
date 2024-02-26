//
// Created by alexander on 29.1.24.
//

#ifndef TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_SERPENT_H_
#define TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_SERPENT_H_

#include <memory>

#include "../encryption.h"
#include "../encryption_mode.h"

namespace crypto {

class Serpent: public Encryption {
 public:
  void set_key() override {};
  void set_mode(std::shared_ptr<EncryptionMode>) override {};
  void Decrypt(std::vector<uint8_t>& data) override {};
  [[nodiscard]] uint16_t GetBlockSize() override { return 16; }
  [[nodiscard]] uint16_t GetKeySize() override { return 32; }
};

} // crypto

#endif //TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_SERPENT_H_

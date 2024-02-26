#ifndef TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_ENCRYPTION_ENCRYPTION_H_
#define TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_ENCRYPTION_ENCRYPTION_H_

#include <memory>
#include <vector>

#include "encryption_mode.h"

namespace crypto {

class Encryption {
 public:
  virtual ~Encryption() = default;
  virtual void set_key() = 0;
  virtual void set_mode(std::shared_ptr<EncryptionMode>) = 0;
  virtual void Decrypt(std::vector<uint8_t> &data) = 0;
  virtual uint16_t GetBlockSize() = 0;
  virtual uint16_t GetKeySize() = 0;
};

} // crypto

#endif //TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_ENCRYPTION_ENCRYPTION_H_

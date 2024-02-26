#ifndef TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_RIPEMD160_H_
#define TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_RIPEMD160_H_

#include "base/base.h"
#include "../hash.h"
#include "truecrypt/Common/Pkcs5.h"

namespace crypto {

class Ripemd160: public Hash {
 public:
  [[nodiscard]] ReturnResult DeriveKey(
      std::vector<uint8_t>& key,
      const std::string& password,
      std::vector<uint8_t>& salt,
      uint32_t iterationCount) const override {

    derive_key_ripemd160(
      FALSE,
      (char *) password.c_str(),
      (int) password.size(),
      reinterpret_cast<char*>(salt.data()),
      static_cast<int>(salt.size()),
      static_cast<int>(iterationCount),
      reinterpret_cast<char*>(key.data()),
      static_cast<int>(key.size())
    );

    return AddSuccess();
  }

  [[nodiscard]] uint32_t GetIterationCount() const override { return 1000; }
};

}

#endif //TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_RIPEMD160_H_

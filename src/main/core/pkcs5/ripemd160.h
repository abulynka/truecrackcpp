#ifndef TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_PKCS5_RIPEMD160_H_
#define TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_PKCS5_RIPEMD160_H_

#include "base/base.h"
#include "../pkcs5kdf.h"
#include "truecrypt/Common/Pkcs5.h"

namespace crypto::pkcs5hmac {

class Ripemd160: public Pkcs5Kdf {
 public:
  [[nodiscard]] ReturnResult DeriveKey (const TrueCrypt::BufferPtr& key, const TrueCrypt::VolumePassword& password, const TrueCrypt::ConstBufferPtr& salt, uint32_t iteration_count) const override {
    auto result = ValidateParameters(key, password, salt, iteration_count);

    if (result->isError()) {
      return AddErrorNext(result);
    }

    derive_key_ripemd160 (
        FALSE,
        (char *) password.DataPtr(),
        (int) password.Size(),
        (char *) salt.Get(),
        (int) salt.Size(),
        (int) iteration_count,
        (char *) key.Get(),
        (int) key.Size());
  }

  [[nodiscard]] uint32_t GetIterationCount() const override { return 2000; }
};

} // crypto::pkcs5hmac

#endif //TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_PKCS5_RIPEMD160_H_

#ifndef TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_PKCS5KDF_H_
#define TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_PKCS5KDF_H_

#include <string>
#include <memory>

#include "base/base.h"

namespace crypto::pkcs5hmac {

class Pkcs5Kdf {
 public:
  virtual ~Pkcs5Kdf () = default;

  [[nodiscard]] virtual ReturnResult DeriveKey (const std::vector<uint8_t>& key, const std::vector<uint8_t>& password, const std::vector<uint8_t>& salt) const {
    return DeriveKey(key, password, salt, GetIterationCount());
  }

 private:
  [[nodiscard]] virtual ReturnResult DeriveKey(const std::vector<uint8_t>& key, const std::vector<uint8_t>& password, const std::vector<uint8_t>& salt, uint32_t iteration_count) const = 0;
  [[nodiscard]] virtual uint32_t GetIterationCount() const = 0;

//  virtual void DeriveKey (const BufferPtr &key, const VolumePassword &password, const ConstBufferPtr &salt, int iterationCount) const = 0;
//  static shared_ptr <Pkcs5Kdf> GetAlgorithm (const wstring &name);
//  static shared_ptr <Pkcs5Kdf> GetAlgorithm (const Hash &hash);
//  static Pkcs5KdfList GetAvailableAlgorithms ();
//  virtual shared_ptr <Hash> GetHash () const = 0;
//  virtual int GetIterationCount () const = 0;
//  virtual wstring GetName () const = 0;
//  virtual bool IsDeprecated () const { return GetHash()->IsDeprecated(); }

 protected:
  [[nodiscard]] static ReturnResult ValidateParameters (std::vector<uint8_t>& key, const std::vector<uint8_t>& password, const std::vector<uint8_t>& salt, uint32_t iterationCount) {
    if (key.empty() || password.empty() || salt.empty() || iterationCount < 1) {
      return AddSystemErrorResult("wrong input data");
    }
    return AddSystemSuccess();
  }

};

} // crypto

#endif //TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_PKCS5KDF_H_

//
// Created by alexander on 17.1.24.
//

#ifndef TRUECRACKCPP_SRC_MAIN_CORE_CRYPT_CRYPT_UTILS_H_
#define TRUECRACKCPP_SRC_MAIN_CORE_CRYPT_CRYPT_UTILS_H_

#include <memory>

#include "main/config/config.h"
#include "decrypt_task.h"
#include "base/base.h"
#include "base/result/result.h"
#include "encryption_algorithm.h"

namespace crypto {

class CryptoUtils {
 public:
  ReturnResult Decrypt(const DecryptTask& task) {
    if (task.get_password().empty()) {
      return AddSystemErrorResult("password is empty");
    }

    uint8_t salt_offset = 0;
    uint8_t salt_size = 64;

    std::vector<uint8_t> salt(task.get_header().begin() + salt_offset, task.get_header().begin() + salt_offset + salt_size);
    std::vector<uint8_t> header_key;

    auto result = task.get_encryption_settings()->get_hash()->DeriveKey(header_key, task.get_password(), salt);

    if (result->isError()) {
      return AddErrorNext(result);
    }

//    foreach (shared_ptr <Pkcs5Kdf> pkcs5, keyDerivationFunctions)
//    {
//      pkcs5->DeriveKey (headerKey, password, salt);
//
//      foreach (shared_ptr <EncryptionMode> mode, encryptionModes)
//      {
//        if (typeid (*mode) != typeid (EncryptionModeXTS))
//          mode->SetKey (headerKey.GetRange (0, mode->GetKeySize()));
//
//        foreach (shared_ptr <EncryptionAlgorithm> ea, encryptionAlgorithms)
//        {
//          if (!ea->IsModeSupported (mode))
//            continue;
//
//          if (typeid (*mode) == typeid (EncryptionModeXTS))
//          {
//            ea->SetKey (headerKey.GetRange (0, ea->GetKeySize()));
//
//            mode = mode->GetNew();
//            mode->SetKey (headerKey.GetRange (ea->GetKeySize(), ea->GetKeySize()));
//          }
//          else
//          {
//            ea->SetKey (headerKey.GetRange (LegacyEncryptionModeKeyAreaSize, ea->GetKeySize()));
//          }
//
//          ea->SetMode (mode);
//
//          header.CopyFrom (encryptedData.GetRange (EncryptedHeaderDataOffset, EncryptedHeaderDataSize));
//          ea->Decrypt (header);
//
//          if (Deserialize (header, ea, mode))
//          {
//            EA = ea;
//            Pkcs5 = pkcs5;
//            return true;
//          }
//        }
//      }
//    }
    return AddUserError();
  }
};

}

#endif //TRUECRACKCPP_SRC_MAIN_CORE_CRYPT_CRYPT_UTILS_H_

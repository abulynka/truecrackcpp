#ifndef TRUECRACKCPP_SRC_MAIN_CORE_HASH_H_
#define TRUECRACKCPP_SRC_MAIN_CORE_HASH_H_

#include "base/base.h"

namespace crypto {

class Hash {
 public:
  [[nodiscard]] ReturnResult DeriveKey(std::vector<uint8_t>& key, const std::string& password, std::vector<uint8_t>& salt) {
    auto result = ValidateParameters(key, password, salt, GetIterationCount());
    if (result->isError()) {
      return AddErrorNext(result);
    }
    return DeriveKey(key, password, salt, GetIterationCount());
  }

  [[nodiscard]] virtual ReturnResult DeriveKey(std::vector<uint8_t>& key, const std::string& password, std::vector<uint8_t>& salt, uint32_t iterationCount) const = 0;
  [[nodiscard]] virtual uint32_t GetIterationCount() const = 0;

 private:
  [[nodiscard]] static ReturnResult ValidateParameters (std::vector<uint8_t>& key, const std::string& password, const std::vector<uint8_t>& salt, uint32_t iterationCount) {
    if (/*key.empty() ||*/ password.empty() || salt.empty() || iterationCount < 1) {
      return AddSystemErrorResult("wrong input data");
    }
    return AddSystemSuccess();
  }
};

} // crypto

#endif //TRUECRACKCPP_SRC_MAIN_CORE_HASH_H_

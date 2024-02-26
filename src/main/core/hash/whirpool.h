#ifndef TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_WHIRPOOL_H_
#define TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_WHIRPOOL_H_

#include "base/base.h"
#include "../hash.h"

namespace crypto {

class Whirpool: public Hash {
 public:
  [[nodiscard]] ReturnResult DeriveKey(
      std::vector<uint8_t>& key,
      const std::string& password,
      std::vector<uint8_t>& salt,
      uint32_t iterationCount) const override {
    return AddSuccess();
  }

  [[nodiscard]] uint32_t GetIterationCount() const override { return 1000; }
};

} // crypto

#endif //TRUECRACKCPP_SRC_MAIN_CORE_CRYPTO_WHIRPOOL_H_

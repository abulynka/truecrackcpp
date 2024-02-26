#ifndef TRUECRACKCPP_SRC_MAIN_CONFIG_CONFIG_UTILS_H_
#define TRUECRACKCPP_SRC_MAIN_CONFIG_CONFIG_UTILS_H_

#include <memory>

#include "config.h"
#include "base/base.h"
#include "utils/file.h"

namespace config {

class ConfigUtils {
 public:
  [[nodiscard]] static ReturnResult Process(std::shared_ptr<Config> config) {
    std::vector<uint8_t> buffer;
//    auto result = utils::File::Read(config->get_volume_path(), 0, config->get_header_size(), buffer);
//    if (result->) {

//    }
    config->set_encrypted_header(buffer);
    return  AddSystemSuccess();
  }
};

} // config

#endif //TRUECRACKCPP_SRC_MAIN_CONFIG_CONFIG_UTILS_H_

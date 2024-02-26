#ifndef TRUECRACKCPP_SRC_MAIN_CONFIG_CONFIG_PARAMS_H_
#define TRUECRACKCPP_SRC_MAIN_CONFIG_CONFIG_PARAMS_H_

#include <string>

namespace config {

class ConfigParams {
 public:
  inline static const std::string HELP = "help";
  inline static const std::string VOLUME_PATH = "volume";
  inline static const std::string KEY_DERIVATION_FUNCTION = "key";
  inline static const std::string ENCRYPTION_ALGORITHM = "encryption_algorithm";
  inline static const std::string ENCRYPTION_MODE = "encryption_mode";
  inline static const std::string ATTACK = "attack";
  inline static const std::string NUMBER = "number";
  inline static const std::string WORDLIST = "word_list";
  inline static const std::string CHARSET = "charset";
  inline static const std::string START_LENGTH = "start_length";
  inline static const std::string MAX_LENGTH = "max_length";
  inline static const std::string REPETITION = "repetition";
  inline static const std::string PREFIX = "prefix";
  inline static const std::string RESTORE = "restore";
  // inline static const std::string BACKUP = "backup";
  // inline static const std::string HIDDEN = "hidden";
  inline static const std::string VERBOSE = "verbose";
};

} // config

#endif //TRUECRACKCPP_SRC_MAIN_CONFIG_CONFIG_PARAMS_H_

#ifndef TRUECRACK_SRC_MAIN_CONFIG_HELPER_H_
#define TRUECRACK_SRC_MAIN_CONFIG_HELPER_H_

#include <string>

namespace config {

class Helper {
 public:
  [[nodiscard]] static const std::string& GetHeader();

 private:
  static inline std::string usage_;
};

} // config

#endif //TRUECRACK_SRC_MAIN_CONFIG_HELPER_H_

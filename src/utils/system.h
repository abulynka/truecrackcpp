#ifndef TRUECRACKCPP_SRC_UTILS_SYSTEM_H_
#define TRUECRACKCPP_SRC_UTILS_SYSTEM_H_

#include <thread>

namespace utils {

class System {
 public:
  [[nodiscard]] static unsigned int getCpuNumber() {
    return std::thread::hardware_concurrency();
  }
};

} // utils

#endif //TRUECRACKCPP_SRC_UTILS_SYSTEM_H_

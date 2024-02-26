#ifndef TRUECRACKCPP_SRC_UTILS_PATH_RESOLVER_H_
#define TRUECRACKCPP_SRC_UTILS_PATH_RESOLVER_H_

#include <string>

#include "utils/strings.h"

namespace utils {

class PathResolver {
 public:
  static const std::string& DocumentRoot() {
    if (document_root_parsed_.empty()) {
      auto path = utils::Strings::split('/', document_root_);
      path.resize(path.size() - 2);
      document_root_parsed_ = utils::Strings::join("/", path);
    }
    return document_root_parsed_;
  }

 private:
  static inline std::string document_root_ = __FILE__;
  static inline std::string document_root_parsed_;
};

} // utils

#endif //TRUECRACKCPP_SRC_UTILS_PATH_RESOLVER_H_

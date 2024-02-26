#ifndef TRUECRACK_CONFIG_PARSER_H
#define TRUECRACK_CONFIG_PARSER_H

#include <memory>

#include <cxxopts.hpp>

#include "config.h"
#include "base/base.h"

namespace config {

class Parser {
 public:
  [[nodiscard]] static ReturnResult Parse(int argc, char** argv, const std::shared_ptr<config::Config>& config);
  [[nodiscard]] static std::unique_ptr<cxxopts::Options> InitOptions();
};

}

#endif //TRUECRACK_CONFIG_PARSER_H

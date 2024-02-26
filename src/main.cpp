#include <memory>
#include <execinfo.h>
#include <cxxabi.h>

#include "main/config/parser.h"
#include "main/config/config_utils.h"
#include "main/core/core.h"
#include "base/result/result.h"
#include "base/log/logging_settings.h"
#include "base/log/logging.h"

bool ProcessResult(std::unique_ptr<base::Result> result) {
  if (!result->isError()) {
    if (result->isUserResult() && !result->get_user_result()->get_message().empty()) {
      log1 << result->get_user_result()->get_message();
    }
    return true;
  }

  if (result->isSystemResult()) {
    log1 << result->get_system_result()->generateErrorMessageWithErrorStack();
    log1 << result->get_system_result()->get_error_message();
  } else if (result->isUserResult()) {
    log1 << result->get_user_result()->get_message();
  }

  return false;
}

int main(int argc, char** argv) {
  try {
    logging::Logging::Init(std::make_unique<logging::LoggingSettings>());

    std::shared_ptr<config::Config> config = std::make_shared<config::Config>();
    if (!ProcessResult(config::Parser::Parse(argc, argv, config))) {
      return EXIT_FAILURE;
    }

    if (!ProcessResult(config::ConfigUtils::Process(config))) {
      return EXIT_FAILURE;
    }

    std::unique_ptr<core::Core> core = std::make_unique<core::Core>(config);

    if (!ProcessResult(core->Process())) {
      return EXIT_FAILURE;
    }
  } catch (const std::exception& e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

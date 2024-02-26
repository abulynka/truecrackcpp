#ifndef TRUECRACKCPP_SRC_BASE_LOG_LOGGING_SETTINGS_H_
#define TRUECRACKCPP_SRC_BASE_LOG_LOGGING_SETTINGS_H_

#include <string>

namespace logging {

class LoggingSettings {
 public:
  // Debug mode
  [[nodiscard]] bool isDebugMode() const { return debug_mode_; }
  void set_debug_mode(bool debug_mode) { debug_mode_ = debug_mode; }

  // Log level
  [[nodiscard]] int log_level() const { return log_level_; }
  void set_log_level(int log_level) { log_level_ = log_level; }

  // Log file name
  [[nodiscard]] const std::string& log_file_name() const { return log_file_name_; }
  void set_log_file_name(std::string log_file_name) {
    log_file_name_ = std::move(log_file_name);
  }

  // Log mechanism
  [[nodiscard]] int get_log_mechanism() { return log_mechanism_; }

  // Application name
  [[nodiscard]] const std::string& app_name() { return app_name_; }
  void set_app_name(std::string app_name) { app_name_ = std::move(app_name); }

  enum {
    LOG_TO_STDOUT,
    LOG_TO_SYSLOG,
    LOG_TO_OWN_FILE_ROTATE
  };

 protected:
  bool debug_mode_ = false;

  int log_level_ = 5;

  std::string log_file_name_;

  int log_mechanism_ = LOG_TO_STDOUT;

  std::string app_name_;
};

} // logging

#endif //TRUECRACKCPP_SRC_BASE_LOG_LOGGING_SETTINGS_H_

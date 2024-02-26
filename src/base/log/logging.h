//
// Created by alexander on 15.1.24.
//

#ifndef TRUECRACKCPP_SRC_BASE_LOG_LOGGING_H_
#define TRUECRACKCPP_SRC_BASE_LOG_LOGGING_H_

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <memory>
#include <iostream>

#include "logging_settings.h"

namespace logging {

class Logging {
 public:

  Logging(std::string file_name,
          int line_name,
          std::string func_name,
          int log_level):
          file_name_(std::move(file_name)),
          line_name_(line_name),
          func_name_(std::move(func_name)),
          log_level_(log_level) {
    if (log_level_ <= logging_settings_->log_level()) {
      enabled_log_ = true;
    }

//    if (log_level <= logging_settings_.log_level()) {
//      enabled_log_ = true;
//
//      int current_pid = 0;
//      ProcessFunctions::Singleton().GetCurrentPid(&current_pid);
//      str_ = StringFunctions::Singleton().ToStr(current_pid)
//          + " "
//          + DocumentRoot::Singleton().ParseFileName(file_name)
//          + " "
//          + StringFunctions::Singleton().ToStr(line_name)
//          + ": "
//          + func_name
//          + "() ";
//    } else {
//      enabled_log_ = false;
//    }
  }

  ~Logging() {
    if (!enabled_log_) {
      return;
    }

    std::cout << str_ << std::endl;

//    if (logging_settings_.log_mechanism()
//        == logging_settings_.LOG_TO_STDOUT()) {
//      std::string red_color = "\033[0;31m";
//      std::string blue_color = "\033[0;34m";
//      std::string no_color = "\033[0m";
//
//      if (current_log_level_ == -1) {
//        str_ = red_color + AddPrefixToEachLine(str_, " lerr ") + no_color;
//      } else if (current_log_level_ == 0) {
//        str_ = blue_color + AddPrefixToEachLine(str_, " ldbg ") + no_color;
//      }
//      std::cout << str_ << std::endl;
//
//    } else if (logging_settings_.log_mechanism()
//        == logging_settings_.LOG_TO_OWN_FILE_ROTATE()) {
//      str_ += "\n";
//
//    } else if (logging_settings_.log_mechanism()
//        == logging_settings_.LOG_TO_SYSLOG()) {
//      std::string str = EscapeStringForSyslog(str_);
//      std::string app_name = logging_settings_.app_name();
//      app_name = EscapeStringForSyslog(app_name);
//
//      openlog(
//          app_name.c_str(),
//          LOG_PID | LOG_CONS | LOG_NDELAY | LOG_NOWAIT, LOG_LOCAL0);
//
//      syslog(LOG_INFO, "%s", str.c_str());
//      closelog();
//    }
  }

  // Init function
  inline static void Init(std::unique_ptr<LoggingSettings> logging_settings) {
    logging_settings_ = std::move(logging_settings);
  }

  // Input operators
  template<class T> Logging &operator<<(const T &v) {
    if (!enabled_log_) {
      return *this;
    }
    std::stringstream out;
    out << v;
    str_ += out.str();
    return *this;
  }

  Logging &operator<<(std::string &str) {
    if (!enabled_log_) {
      return *this;
    }
    str_ += str;
    return *this;
  }

  Logging &operator<<(
      const std::vector<std::map<std::string, std::string>> &data);

  Logging &operator<<(
      const std::map<std::string, std::string> &data);

  Logging &operator<<(
      const std::vector<int> &data);

  Logging &operator<<(
      const std::vector<std::string> &data);

 protected:
  // Logging settings
  inline static std::shared_ptr<LoggingSettings> logging_settings_;

  // Escapes string for syslog
  std::string EscapeStringForSyslog(const std::string &str);

  // Adds prefix to each line
  std::string AddPrefixToEachLine(std::string &str, std::string prefix);

  // String with current log ready to output
  std::string str_;

  bool enabled_log_;

  std::string file_name_;
  int line_name_;
  std::string func_name_;
  int log_level_;
};

} // logging

#define log_test logging::Logging(__FILE__, __LINE__, __FUNCTION__, 2)
#define log_error logging::Logging(__FILE__, __LINE__, __FUNCTION__, -1)
#define log_debug logging::Logging(__FILE__, __LINE__, __FUNCTION__, 0)
#define log1 logging::Logging(__FILE__, __LINE__, __FUNCTION__, 1)
#define log3 logging::Logging(__FILE__, __LINE__, __FUNCTION__, 3)
#define log5 logging::Logging(__FILE__, __LINE__, __FUNCTION__, 5)
#define log7 logging::Logging(__FILE__, __LINE__, __FUNCTION__, 7)

#endif //TRUECRACKCPP_SRC_BASE_LOG_LOGGING_H_

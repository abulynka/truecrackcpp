//
// Created by alexander on 15.1.24.
//

#include "logging.h"
#include "utils/file.h"

#include <memory>

// Adds prefix to each line
std::string logging::Logging::AddPrefixToEachLine(std::string &str, std::string prefix) {
//  std::shared_ptr<StringFunctions> sf = std::make_shared<StringFunctions>();
//  std::vector<std::string> lines = sf->Split(sf->GetEOL(), str);
  std::string result;
//  for (auto line : lines) {
//    result += prefix + line + sf->GetEOL();
//  }
  return result;
}

logging::Logging& logging::Logging::operator<<(
    const std::vector<std::map<std::string, std::string>> &data) {
  if (!enabled_log_) {
    return *this;
  }
//  str_ = "Data: \n";
//  int counter = 0;
//  for (auto i : data) {
//    str_ += "["
//        + StringFunctions::Singleton().ToStr(++counter)
//        + "] =>"
//        + StringFunctions::Singleton().GetEOL();
//    for (auto j : i) {
//      str_ += "\t[" + j.first + "] => " + j.second + "\n";
//    }
//  }
  return *this;
}

logging::Logging& logging::Logging::operator<<(
    const std::map<std::string, std::string> &data) {
  if (!enabled_log_) {
    return *this;
  }
//  str_ = "Data: \n";
//  for (auto i : data) {
//    str_ += "[" + i.first + "] => " + i.second;
//  }
  return *this;
}

logging::Logging& logging::Logging::operator<<(
    const std::vector<int> &data) {
  if (!enabled_log_) {
    return *this;
  }
//  str_ = "Data: \n";
//  int counter = 0;
//  for (auto i : data) {
//    str_ += "[" + StringFunctions::Singleton().ToStr(++counter) + "] => "
//        + StringFunctions::Singleton().ToStr(i)
//        + "\n";
//  }
  return *this;
}

logging::Logging& logging::Logging::operator<<(
    const std::vector<std::string> &data) {
  if (!enabled_log_) {
    return *this;
  }
//  str_ = "Data: \n";
//  int counter = 0;
//  for (auto i : data) {
//    str_ += "[" + StringFunctions::Singleton().ToStr(++counter) + "] => "
//        + i
//        + "\n";
//  }
  return *this;
}

// Escapes string for syslog
std::string logging::Logging::EscapeStringForSyslog(const std::string &str) {
  std::string result;
  for (const auto &i : str) {
    if (i == '%') {
      result += "%%";
    } else {
      result += i;
    }
  }
  return result;
}

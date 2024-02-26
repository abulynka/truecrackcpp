#ifndef TRUECRACK_SRC_MAIN_CONFIG_INFO_H_
#define TRUECRACK_SRC_MAIN_CONFIG_INFO_H_

#include <string>

namespace config {

class Info {
 public:
  static inline const std::string SOFTWARE = "TrueCrackCPP";
  static inline const std::string PROGRAM_NAME = "truecrackcpp";
  static inline const std::string VERSION = "3.6";
  static inline const std::string WEBSITE = "https://github.com/abulynka/truecrack";
  static inline const std::string AUTHOR = "Aliaksandr Bulynka";
  static inline const std::string EMAIL = "abulynka@gmail.com";
  static inline const std::string MESSAGE = "Bruteforce password cracker for Truecrypt volume. Based on TrueCrack (https://github.com/lvaccaro/truecrack) and TrueCrypt (currently veracrypt https://github.com/veracrypt/VeraCrypt) projects. Copyright (c) 2024 by Aliaksandr Bulynka.";
};

} // config

#endif //TRUECRACK_SRC_MAIN_CONFIG_INFO_H_

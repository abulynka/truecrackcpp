#include <string>
#include <memory>
#include <vector>

#include <cxxopts.hpp>

#include "parser.h"
#include "helper.h"
#include "info.h"
#include "config_params.h"
#include "utils/system.h"
#include "utils/file.h"

ReturnResult config::Parser::Parse(int argc, char** argv, const std::shared_ptr<config::Config>& config) {
  std::unique_ptr<cxxopts::Options> options = InitOptions();
  auto result = options->parse(argc, argv);

  if (result.count(ConfigParams::HELP)) {
    return AddUserErrorResult(options->help());
  }

  if (result.count(ConfigParams::VOLUME_PATH)) {
    std::string volume_path = result[ConfigParams::VOLUME_PATH].as<std::string>();
    if (!utils::File::Exists(volume_path)) {
      return AddUserErrorResult("file " + volume_path + " doesn't exist");
    }
    config->set_volume_path(volume_path);
  } else {
    return AddUserErrorResult(ConfigParams::VOLUME_PATH + " can't be empty");
  }

  std::vector<std::string> key_derivation_functions = result[ConfigParams::KEY_DERIVATION_FUNCTION].as<std::vector<std::string>>();
  for (const std::string& key: key_derivation_functions) {
    if (key == "ripemd160") {
      config->add_key_derivation_function(Config::KeyDerivationFunction::RIPEMD160);
    } else if (key == "sha512") {
      config->add_key_derivation_function(Config::KeyDerivationFunction::SHA512);
    } else if (key == "whirlpool") {
      config->add_key_derivation_function(Config::KeyDerivationFunction::WHIRLPOOL);
    } else {
      return AddUserErrorResult("unknow deriviation function '" + key + "'");
    }
  }

  std::vector<std::string> encryption_algorithms = result[ConfigParams::ENCRYPTION_ALGORITHM].as<std::vector<std::string>>();
  std::unordered_map<std::string, Config::EncryptionAlgorithm> encryption_map = {
      {"aes", Config::EncryptionAlgorithm::AES},
      {"serpent", Config::EncryptionAlgorithm::SERPENT},
      {"twofish", Config::EncryptionAlgorithm::TWOFISH},
      {"aes-twofish", Config::EncryptionAlgorithm::AES_TWOFISH},
      {"aes-twofish-serpent", Config::EncryptionAlgorithm::AES_TWOFISH_SERPENT},
      {"serpent-aes", Config::EncryptionAlgorithm::SERPENT_AES},
      {"serpent-twofish-aes", Config::EncryptionAlgorithm::SERPENT_TWOFISH_AES},
      {"twofish-serpent", Config::EncryptionAlgorithm::TWOFISH_SERPENT}
  };
  for (const std::string& encryption : encryption_algorithms) {
    auto it = encryption_map.find(encryption);
    if (it != encryption_map.end()) {
      config->add_encryption_algorithm(it->second);
    } else {
      return AddUserErrorResult("unknown encryption algorithm '" + encryption + "'");
    }
  }

  std::vector<std::string> encryption_modes = result[ConfigParams::ENCRYPTION_MODE].as<std::vector<std::string>>();
  for (const std::string& encryption_mode: encryption_modes) {
    if (encryption_mode == "xts") {
      config->add_encryption_mode(Config::EncryptionMode::XTS);
    } else if (encryption_mode == "lrw") {
      config->add_encryption_mode(Config::EncryptionMode::LRW);
    } else if (encryption_mode == "cbc") {
      config->add_encryption_mode(Config::EncryptionMode::CBC);
    } else {
      return AddUserErrorResult("unknow encryption mode '" + encryption_mode + "'");
    }
  }

  if (result.count(ConfigParams::ATTACK)) {
    std::string attack = result[ConfigParams::ATTACK].as<std::string>();
    if (attack == "dictionary") {
      config->set_attack_type(Config::AttackType::kDictionary);
    } else if (attack == "alphabet") {
      config->set_attack_type(Config::AttackType::kCharset);
    } else {
      return AddUserErrorResult("unknown attack type: " + attack);
    }
  } else {
    return AddUserErrorResult(ConfigParams::ATTACK + " can't be empty");
  }

  std::string number = result[ConfigParams::NUMBER].as<std::string>();
  unsigned int num;
  if (number == "auto") {
    num = utils::System::getCpuNumber();
  } else {
    num = std::stoul(number);
  }
  if (num < 1) {
    return AddUserErrorResult(ConfigParams::NUMBER + " should be number and greater than zero");
  }
  config->set_number_of_parallel_computations(num);

  if (result.count(ConfigParams::WORDLIST)) {
    std::string wordlist = result[ConfigParams::WORDLIST].as<std::string>();
    if (!utils::File::Exists(wordlist)) {
      return AddUserErrorResult("file " + wordlist + " doesn't exist or permission denied");
    }
    config->set_words_path(wordlist);
  }

  if (result.count(ConfigParams::CHARSET)) {
    std::string charset = result[ConfigParams::CHARSET].as<std::string>();
    if (charset.empty()) {
      return AddUserErrorResult(ConfigParams::CHARSET + " can't be empty");
    }
    config->set_charset(charset);
  }

  unsigned int start_length = result[ConfigParams::START_LENGTH].as<unsigned int>();
  if (start_length < 1) {
    return AddUserErrorResult(ConfigParams::START_LENGTH + " param should be a number and be greater than 0");
  }
  config->set_min_length(start_length);

  unsigned int max_length = result[ConfigParams::MAX_LENGTH].as<int>();
  if (max_length < 1) {
    return AddUserErrorResult(ConfigParams::MAX_LENGTH + " param should be a number and be greater than 0");
  }
  config->set_max_length(max_length);

  if (start_length > max_length) {
    return AddUserErrorResult(ConfigParams::START_LENGTH + " should be greater or equal than " + ConfigParams::MAX_LENGTH);
  }

  std::string repetition = result[ConfigParams::REPETITION].as<std::string>();
  if (repetition == "yes") {
    config->set_repetition(Config::CharsetRepetition::YES);
  } else {
    config->set_repetition(Config::CharsetRepetition::NO);
  }

  if (result.count(ConfigParams::PREFIX)) {
    config->set_prefix(result[ConfigParams::PREFIX].as<std::string>());
  }

  config->set_restore(result[ConfigParams::RESTORE].as<int>());

  if (result.count(ConfigParams::VERBOSE)) {
    config->set_verbose(true);
  }

  return AddSystemSuccess();
}

std::unique_ptr<cxxopts::Options> config::Parser::InitOptions() {
  std::unique_ptr<cxxopts::Options> options = std::make_unique<cxxopts::Options>(Info::PROGRAM_NAME, Helper::GetHeader());
  options->add_options()
      ("h," + ConfigParams::HELP, "display this information")
      ("t," + ConfigParams::VOLUME_PATH, "truecrypt volume file", cxxopts::value<std::string>())
      (
          "k," + ConfigParams::KEY_DERIVATION_FUNCTION,
          "key derivation function (possible multiple values): <ripemd160 | sha512 | whirlpool>",
          cxxopts::value<std::vector<std::string>>()
              ->default_value("ripemd160")
      )
      (
          "e," + ConfigParams::ENCRYPTION_ALGORITHM,
          "encryption algorithm (possible multiple values): <aes | serpent | twofish | aes-twofish | aes-twofish-serpent | serpent-aes | serpent-twofish-aes | twofish-serpent>",
          cxxopts::value<std::vector<std::string>>()
              ->default_value("aes")
      )
      (
          "f," + ConfigParams::ENCRYPTION_MODE,
          "encryption mode (possible multiple values): <xts | lrw | cbc>",
          cxxopts::value<std::vector<std::string>>()
              ->default_value("xts")
      )
      (
          "a," + ConfigParams::ATTACK,
          "attack type: <dictionary | alphabet>",
          cxxopts::value<std::string>()
      )
      (
          "n," + ConfigParams::NUMBER,
          "number of parallel computations: <auto, 1, 2, 3, ...>",
          cxxopts::value<std::string>()
              ->default_value("auto")
      )
      (
          "w," + ConfigParams::WORDLIST,
          "file of words, for dictionary attack",
          cxxopts::value<std::string>()
      )
      (
          "c," + ConfigParams::CHARSET,
          "alphabet generator, for alphabet attack",
          cxxopts::value<std::string>()
      )
      (
          "s," + ConfigParams::START_LENGTH,
          "starting length of passwords, for alphabet attack",
          cxxopts::value<unsigned int>()
              ->default_value("1")
      )
      (
          "m," + ConfigParams::MAX_LENGTH,
          "maximum length of passwords, for alphabet attack",
          cxxopts::value<int>()
              ->default_value("10")
      )
      (
          "x," + ConfigParams::REPETITION,
          "with (yes) [[1, 1], [1, 2], [2, 1], [2, 2]] or without (no) [[1, 2], [2, 1]] repetition, for alphabet attack: <yes | no>",
          cxxopts::value<std::string>()
              ->default_value("yes")
      )
      (
          "p," + ConfigParams::PREFIX,
          "prefix the first part of the password, for alphabet attack",
          cxxopts::value<std::string>()
      )
      (
          "r," + ConfigParams::RESTORE,
          "restore the computation",
          cxxopts::value<int>()
                ->default_value("0")
      )
      /*
      (
          "b," + ConfigParams::BACKUP,
          "backup header instead of volume header",
          cxxopts::value<std::string>()
      )
      (
          "H," + ConfigParams::HIDDEN,
          "hidden truecrypt volume",
          cxxopts::value<std::string>()
      )
      */
      (
          "v," + ConfigParams::VERBOSE,
          "show computation messages",
          cxxopts::value<bool>()
              ->default_value("false")
      );

  return options;
}

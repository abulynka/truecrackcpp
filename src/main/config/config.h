#ifndef TRUECRACK_CONFIG_H
#define TRUECRACK_CONFIG_H

#include <string>
#include <utility>
#include <vector>

namespace config {

class Config {
 public:
  enum class EncryptionAlgorithm {
    AES,
    SERPENT,
    TWOFISH,
    AES_TWOFISH,
    AES_TWOFISH_SERPENT,
    SERPENT_AES,
    SERPENT_TWOFISH_AES,
    TWOFISH_SERPENT
  };

  enum class KeyDerivationFunction {
    RIPEMD160,
    SHA512,
    WHIRLPOOL,
  };

  enum class EncryptionMode {
    XTS,
    LRW,
    CBC,
  };

  enum class CharsetRepetition {
    YES,
    NO
  };

  [[nodiscard]] const std::string& get_volume_path() {
    return volume_path_;
  }

  void set_volume_path(std::string volume_path) {
    volume_path_ = std::move(volume_path);
  }

  [[nodiscard]] const std::string& get_words_path() {
    return words_path_;
  }

  void set_words_path(std::string words_path) {
    words_path_ = std::move(words_path);
  }

  [[nodiscard]] const std::string& get_charset() {
    return charset_;
  }

  void set_charset(std::string charset) {
    charset_ = std::move(charset);
  }

  enum class AttackType {
    kDictionary,
    kCharset,
  };

  [[nodiscard]] AttackType get_attack_type() {
    return attack_type_;
  }

  void set_attack_type(AttackType attack_type) {
    attack_type_ = attack_type;
  }

  [[nodiscard]] uint32_t get_max_length() const {
    return max_length_;
  }

  void set_max_length(uint32_t max_length) {
    max_length_ = max_length;
  }

  [[nodiscard]] uint32_t get_min_length() const {
    return min_length_;
  }

  void set_min_length(uint32_t min_length) {
    min_length_ = min_length;
  }

  void set_verbose(bool verbose) {
    verbose_ = verbose;
  }

  [[nodiscard]] bool isVerbose() const {
    return verbose_;
  }

  void set_restore(uint64_t restore) {
    restore_ = restore;
  }

  [[nodiscard]] uint64_t get_restore() const {
    return restore_;
  }

  void set_prefix(std::string prefix) {
    prefix_ = std::move(prefix);
  }

  [[nodiscard]] const std::string& get_prefix() const {
    return prefix_;
  }

  void add_encryption_algorithm(EncryptionAlgorithm algorithm) {
    encryption_algorithms_.push_back(algorithm);
  }

  [[nodiscard]] std::vector<EncryptionAlgorithm> get_encryption_algorithms() const {
    return encryption_algorithms_;
  }

  void add_key_derivation_function(KeyDerivationFunction key_derivation_functions) {
    key_derivation_functions_.push_back(key_derivation_functions);
  }

  [[nodiscard]] std::vector<KeyDerivationFunction> get_key_derivation_functions() const {
    return key_derivation_functions_;
  }

  void add_encryption_mode(EncryptionMode mode) {
    encryption_modes_.push_back(mode);
  }

  [[nodiscard]] std::vector<EncryptionMode> get_encryption_modes() const {
    return encryption_modes_;
  }

  void set_encrypted_header(std::vector<uint8_t> encrypted_header) {
    encrypted_header_ = std::move(encrypted_header);
  }

  [[nodiscard]] const std::vector<uint8_t>& get_encrypted_header() {
    return encrypted_header_;
  }

  void set_number_of_parallel_computations(uint32_t number_of_parallel_computations) {
    number_of_parallel_computations_ = number_of_parallel_computations;
  }

  [[nodiscard]] uint32_t get_number_of_parallel_computations() const {
    return number_of_parallel_computations_;
  }

  [[nodiscard]] uint32_t get_header_size() {
    return 512;
  }

  void set_repetition(CharsetRepetition repetition) {
    repetition_ = repetition;
  }

  [[nodiscard]] CharsetRepetition get_repetition() {
    return repetition_;
  }

 private:
  std::string volume_path_;
  std::string words_path_;
  std::string charset_;
  uint32_t max_length_;
  uint32_t min_length_;
  AttackType attack_type_;
  bool verbose_;
  uint64_t restore_;
  std::string prefix_;
  std::vector<EncryptionAlgorithm> encryption_algorithms_;
  std::vector<KeyDerivationFunction> key_derivation_functions_;
  std::vector<EncryptionMode> encryption_modes_;
  std::vector<uint8_t> encrypted_header_;
  uint32_t number_of_parallel_computations_;
  CharsetRepetition repetition_;
};

}

#endif //TRUECRACK_CONFIG_H

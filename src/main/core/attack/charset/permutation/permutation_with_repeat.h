#ifndef TRUECRACKCPP_SRC_MAIN_CORE_ATTACK_CHARSET_PERMUTATION_PERMUTATION_WITH_REPEAT_H_
#define TRUECRACKCPP_SRC_MAIN_CORE_ATTACK_CHARSET_PERMUTATION_PERMUTATION_WITH_REPEAT_H_

#include "permutation.h"

namespace core::attack {

class PermutationWithRepeat: public Permutation {
 public:
  uint64_t getMaxNumberOfCombinations(uint32_t number_of_characters, uint32_t min_length, uint32_t max_length) override {
    uint64_t max_combinations = 0;
    for (uint32_t i = min_length; i <= max_length; ++i) {
      max_combinations += getMaxNumberOfCombinations(number_of_characters, i);
    }
    return max_combinations;
  }

  uint64_t getMaxNumberOfCombinations(uint32_t numberOfCharacters, uint32_t length) override {
    uint64_t result = 1;
    for (uint32_t i = 0; i < length; i++) {
      result *= numberOfCharacters;
    }
    return result;
  }

  std::string getCombination(const std::string& chars, uint32_t length, uint64_t permutation_number) override {
    std::string combination(length, ' ');
    uint64_t temp = permutation_number;
    for (uint32_t i = 0; i < length; ++i) {
      combination[length - 1 - i] = chars[temp % chars.size()];
      temp /= chars.size();
    }
    return combination;
  }
};

}

#endif //TRUECRACKCPP_SRC_MAIN_CORE_ATTACK_CHARSET_PERMUTATION_PERMUTATION_WITH_REPEAT_H_

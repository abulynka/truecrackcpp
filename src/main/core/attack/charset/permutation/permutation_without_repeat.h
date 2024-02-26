#ifndef TRUECRACKCPP_SRC_MAIN_CORE_ATTACK_CHARSET_PERMUTATION_PERMUTATION_WITHOUT_REPEAT_H_
#define TRUECRACKCPP_SRC_MAIN_CORE_ATTACK_CHARSET_PERMUTATION_PERMUTATION_WITHOUT_REPEAT_H_

#include <algorithm>

#include "permutation.h"

namespace core::attack {

class PermutationWithoutRepeat: public Permutation {
 public:
  uint64_t getMaxNumberOfCombinations(uint32_t number_of_characters, uint32_t min_length, uint32_t max_length) override {
    uint64_t max_combinations = 0;
    max_length = std::min(max_length, number_of_characters);
    for (uint32_t i = min_length; i <= max_length; ++i) {
      max_combinations += getMaxNumberOfCombinations(number_of_characters, i);
    }
    return max_combinations;
  }

  uint64_t getMaxNumberOfCombinations(uint32_t numberOfCharacters, uint32_t length) override {
    if (numberOfCharacters < length) {
      return 0;
    }
    return factorial(numberOfCharacters) / factorial(numberOfCharacters - length);
  }

  std::string getCombination(const std::string& chars, uint32_t length, uint64_t permutation_number) override {
    precomputedFactorials(chars.size());

    std::string result;
    std::string sortedChars = chars;
    std::sort(sortedChars.begin(), sortedChars.end());

    for (uint32_t remainingLength = length; remainingLength > 0; --remainingLength) {
      uint64_t chunkSize = getMaxNumberOfCombinations(sortedChars.size() - 1, remainingLength - 1);
      uint32_t selectedCharIndex = permutation_number / chunkSize;
      result += sortedChars[selectedCharIndex];

      sortedChars.erase(sortedChars.begin() + selectedCharIndex);
      permutation_number %= chunkSize;
    }

    return result;
  }

 private:
  inline static std::vector<uint64_t> factorials_;

  static void precomputedFactorials(uint32_t maxSize) {
    if (factorials_.empty()) {
      factorials_.resize(1, 1);
    }

    if (factorials_.size() >= maxSize) {
      return;
    }

    uint32_t start = factorials_.size();
    factorials_.resize(maxSize + 1, 1);
    for (uint32_t i = start; i <= maxSize; ++i) {
      factorials_[i] = factorials_[i - 1] * i;
    }
  }
};

}

#endif //TRUECRACKCPP_SRC_MAIN_CORE_ATTACK_CHARSET_PERMUTATION_PERMUTATION_WITHOUT_REPEAT_H_

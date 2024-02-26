#ifndef TRUECRACKCPP_SRC_UTILS_PERMUTATION_H_
#define TRUECRACKCPP_SRC_UTILS_PERMUTATION_H_

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace core::attack {

class Permutation {
 public:
  virtual ~Permutation() = default;

  uint64_t factorial(uint32_t n) {
    uint64_t fact = 1;
    for (uint32_t i = 2; i <= n; ++i) {
      fact *= i;
    }
    return fact;
  }

  virtual uint64_t getMaxNumberOfCombinations(uint32_t number_of_characters, uint32_t min_length, uint32_t max_length) = 0;
  virtual uint64_t getMaxNumberOfCombinations(uint32_t numberOfCharacters, uint32_t length) = 0;
  virtual std::string getCombination(const std::string& chars, uint32_t length, uint64_t permutation_number) = 0;
};

} // utils

#endif //TRUECRACKCPP_SRC_UTILS_PERMUTATION_H_

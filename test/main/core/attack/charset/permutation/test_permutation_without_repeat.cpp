#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "main/core/attack/charset/permutation/permutation_without_repeat.h"

class PermutationWithoutRepeatTest : public ::testing::Test {
 protected:
  core::attack::PermutationWithoutRepeat permutation_;
};

TEST_F(PermutationWithoutRepeatTest, get_max_number_of_combinations) {
  ASSERT_EQ(permutation_.getMaxNumberOfCombinations(2, 2), 2);
}

TEST_F(PermutationWithoutRepeatTest, get_max_number_of_combinations_min_max) {
  ASSERT_EQ(permutation_.getMaxNumberOfCombinations(2, 2, 3), 2);
}

TEST_F(PermutationWithoutRepeatTest, get_combination) {
  std::vector<std::tuple<std::string, uint32_t, std::vector<std::string>>> tuples = {
      {"ab", 2, {"ab", "ba"}},
      {"abc", 2, {"ab", "ac", "ba", "bc", "ca", "cb"}},
      {"abc", 3, {"abc", "acb", "bac", "bca", "cab", "cba"}},
      {"abcd", 2, {"ab", "ac", "ad", "ba", "bc", "bd", "ca", "cb", "cd", "da", "db", "dc"}},
      {"abcd", 3, {
          "abc", "abd", "acb", "acd", "adb", "adc",
          "bac", "bad", "bca", "bcd", "bda", "bdc",
          "cab", "cad", "cba", "cbd", "cda", "cdb",
          "dab", "dac", "dba", "dbc", "dca", "dcb"
      }},
      {"abcd", 4, {
          "abcd", "abdc", "acbd", "acdb", "adbc", "adcb",
          "bacd", "badc", "bcad", "bcda", "bdac", "bdca",
          "cabd", "cadb", "cbad", "cbda", "cdab", "cdba",
          "dabc", "dacb", "dbac", "dbca", "dcab", "dcba"
      }},
      {"abcde", 2, {"ab", "ac", "ad", "ae", "ba", "bc", "bd", "be", "ca", "cb", "cd", "ce", "da", "db", "dc", "de", "ea", "eb", "ec", "ed"}},
  };

  for (const auto& tuple: tuples) {
    uint32_t length = std::get<1>(tuple);
    uint64_t number = permutation_.getMaxNumberOfCombinations(std::get<0>(tuple).size(), length);
    std::vector<std::string> results = std::get<2>(tuple);
    ASSERT_EQ(number, results.size());
    for (uint64_t i = 0; i < number; ++i) {
      ASSERT_EQ(permutation_.getCombination(std::get<0>(tuple), length, i), results[i]);
    }
  }
}

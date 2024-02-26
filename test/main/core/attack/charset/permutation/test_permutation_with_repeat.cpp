#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "main/core/attack/charset/permutation/permutation_with_repeat.h"

class PermutationWithRepeatTest : public ::testing::Test {
 protected:
  core::attack::PermutationWithRepeat permutation_;
};

TEST_F(PermutationWithRepeatTest, get_max_number_of_combinations) {
  ASSERT_EQ(permutation_.getMaxNumberOfCombinations(2, 2), 4);
}

TEST_F(PermutationWithRepeatTest, get_max_number_of_combinations_min_max) {
  ASSERT_EQ(permutation_.getMaxNumberOfCombinations(2, 2, 3), 12);
}

TEST_F(PermutationWithRepeatTest, get_combination) {
  std::vector<std::tuple<std::string, uint32_t, std::vector<std::string>>> tuples = {
      {"ab", 2, {"aa", "ab", "ba", "bb"}},
      {"abc", 2, {"aa", "ab", "ac", "ba", "bb", "bc", "ca", "cb", "cc"}},
      {"abc", 3, {
          "aaa", "aab", "aac", "aba", "abb", "abc", "aca", "acb", "acc",
          "baa", "bab", "bac", "bba", "bbb", "bbc", "bca", "bcb", "bcc",
          "caa", "cab", "cac", "cba", "cbb", "cbc", "cca", "ccb", "ccc"
      }},
      {"abcd", 2, {"aa", "ab", "ac", "ad", "ba", "bb", "bc", "bd", "ca", "cb", "cc", "cd", "da", "db", "dc", "dd"}},
      {"abcd", 3, {
          "aaa", "aab", "aac", "aad", "aba", "abb", "abc", "abd", "aca", "acb", "acc", "acd", "ada", "adb", "adc", "add",
          "baa", "bab", "bac", "bad", "bba", "bbb", "bbc", "bbd", "bca", "bcb", "bcc", "bcd", "bda", "bdb", "bdc", "bdd",
          "caa", "cab", "cac", "cad", "cba", "cbb", "cbc", "cbd", "cca", "ccb", "ccc", "ccd", "cda", "cdb", "cdc", "cdd",
          "daa", "dab", "dac", "dad", "dba", "dbb", "dbc", "dbd", "dca", "dcb", "dcc", "dcd", "dda", "ddb", "ddc", "ddd"
      }},
      {"abcde", 2, {"aa", "ab", "ac", "ad", "ae", "ba", "bb", "bc", "bd", "be", "ca", "cb", "cc", "cd", "ce", "da", "db", "dc", "dd", "de", "ea", "eb", "ec", "ed", "ee"}},
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

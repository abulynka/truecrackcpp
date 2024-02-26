//#include "gtest/gtest.h"
//#include "gmock/gmock.h"
//
//#include <vector>
//#include <string>
//
//#include "main/core/attack/charset/utils_charset.h"
//
//TEST(utils_charset, compute_combination) {
//  std::string charset = "abc";
//  int min_length = 1;
//  int max_length = 3;
//  std::vector<std::string> result;
//  std::vector<std::string> data = {
//      "a","b", "c",
//      "aa", "ba", "ca", "ab", "bb", "cb", "ac", "bc", "cc",
//      "aaa", "baa", "caa", "aba", "bba", "cba", "aca", "bca", "cca",
//      "aab", "bab", "cab", "abb", "bbb", "cbb", "acb", "bcb", "ccb",
//      "aac", "bac", "cac", "abc", "bbc", "cbc", "acc", "bcc", "ccc",
//  };
//
//  for (int i = min_length; i <= max_length; ++i) {
//    unsigned long long int max_combination = 1;
//    for (int j = 0; j < i; ++j) {
//      max_combination *= charset.size();
//    }
//
//    unsigned long long int block = 0;
//    for (; block < max_combination; ++block) {
//      result.push_back(std::move(core::attack::UtilsCharset::ComputeCombination(block, max_combination, charset, i)));
//    }
//  }
//
//  std::sort(result.begin(), result.end());
//  std::sort(data.begin(), data.end());
//
//  ASSERT_THAT (result, testing::ElementsAreArray(data));
//}
//
//TEST(utils_charset, get_max_compute_combination_number) {
//  ASSERT_EQ(core::attack::UtilsCharset::GetMaxCombinationsNumber(1, 3, 3), 39);
//  ASSERT_EQ(core::attack::UtilsCharset::GetMaxCombinationsNumber(1, 2, 3), 12);
//}

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "main/core/attack/charset/permutation/permutation.h"

class MockPermutation: public core::attack::Permutation {
 public:
  uint64_t getMaxNumberOfCombinations(uint32_t number_of_characters, uint32_t min_length, uint32_t max_length) override { return 0; }
  uint64_t getMaxNumberOfCombinations(uint32_t numberOfCharacters, uint32_t length) override { return 0; }
  std::string getCombination(const std::string& chars, uint32_t length, uint64_t permutation_number) override { return ""; }
};

class PermutationTest : public ::testing::Test {
 protected:
  MockPermutation permutation_;
};

TEST_F(PermutationTest, factorial) {
  ASSERT_EQ(permutation_.factorial(1), 1);
  ASSERT_EQ(permutation_.factorial(2), 2);
  ASSERT_EQ(permutation_.factorial(3), 6);
  ASSERT_EQ(permutation_.factorial(4), 24);
  ASSERT_EQ(permutation_.factorial(5), 120);
}

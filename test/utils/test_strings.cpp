#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "utils/strings.h"

TEST(utils_strings, split) {
  ASSERT_THAT (utils::Strings::split('_', "a_b_c"), testing::ElementsAre("a", "b", "c"));
  ASSERT_THAT (utils::Strings::split('_', ""), testing::ElementsAre());
  ASSERT_THAT (utils::Strings::split('_', "a"), testing::ElementsAre("a"));
  ASSERT_THAT (utils::Strings::split('_', "a_b"), testing::ElementsAre("a", "b"));
}

TEST(utils_strings, join) {
  ASSERT_EQ(utils::Strings::join("", {""}), "");
  ASSERT_EQ(utils::Strings::join("", {"a", "b", "c"}), "abc");
  ASSERT_EQ(utils::Strings::join("_", {""}), "");
  ASSERT_EQ(utils::Strings::join("_", {"a"}), "a");
  ASSERT_EQ(utils::Strings::join("_", {"a", "b", "c"}), "a_b_c");
}

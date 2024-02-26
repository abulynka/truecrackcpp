#include "gtest/gtest.h"
#include "utils/path_resolver.h"

TEST(utils_file, document_root) {
  std::string document_root = std::string(__FILE__);
  document_root.resize(document_root.size() - std::string("/test/utils/test_path_resolver.cpp").size());
  document_root += "/src";
  ASSERT_EQ(document_root, utils::PathResolver::DocumentRoot());
}

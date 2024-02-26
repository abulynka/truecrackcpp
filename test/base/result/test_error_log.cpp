#include "gtest/gtest.h"

#include "base/result/error_log.h"

TEST(base_result_error_log, get_error_log) {
  std::string document_root = std::string(__FILE__);
  document_root.resize(document_root.size() - std::string("/test/base/result/test_error_log.php").size());
  std::string file_path = document_root + "/src/test.cpp";

  base::ErrorLog error_log(file_path, 1, "test");
  ASSERT_EQ(error_log.get_file_name(), "test.cpp");
}

//
// Created by alexander on 12.12.23.
//

#include <numeric>
#include <iterator>
#include <iostream>

#include "strings.h"

namespace utils {
  std::vector<std::string> Strings::split(char separator, const std::string& string) {
    auto to_string = [](auto&& r) -> std::string {
      const auto data = &*r.begin();
      const auto size = static_cast<std::size_t>(std::ranges::distance(r));
      return std::string{data, size};
    };

    const auto range = string |
        std::ranges::views::split(separator) |
        std::ranges::views::transform(to_string);

    return {std::ranges::begin(range), std::ranges::end(range)};
  }

  std::string Strings::join(const std::string& separator, const std::vector<std::string>& array) {
    std::stringstream ss;
    std::copy(array.begin(), array.end() - 1, std::ostream_iterator<std::string>(ss, separator.c_str()));
    if (!array.empty()) {
      ss << array.back().c_str();
    }
    return ss.str();
  }
} // string
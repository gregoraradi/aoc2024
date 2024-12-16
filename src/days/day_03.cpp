#include "day_03.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <regex>

namespace aoc2024 {

std::uint32_t Day_03::run(std::vector<std::string> const &data) {
  return part1(data);
}

std::uint32_t Day_03::part1(std::vector<std::string> const &data) {

  std::uint32_t sum{0};
  std::regex pattern{R"(mul\(\d{1,3},\d{1,3}\))"};
  for (auto const &line : data) {

    std::sregex_iterator begin(line.begin(), line.end(), pattern);

    std::sregex_iterator end;

    for (auto it = begin; it != end; ++it) {

      std::smatch match = *it;

      std::string element = match.str();

      std::cout << "Match: " << match.str() << std::endl;

      std::regex num_pattern(R"(\d{1,3})");

      std::sregex_iterator begin2(element.begin(), element.end(), num_pattern);

      std::sregex_iterator end2;

      std::string lhs_str{begin2->str()};

      std::advance(begin2, 1);

      std::string rhs_str{begin2->str()};

      std::uint32_t product =
          std::atoi(lhs_str.c_str()) * std::atoi(rhs_str.c_str());

      sum += product;
    }
  }
  return sum;
}

std::uint32_t Day_03::part2(std::vector<std::string> const &data) { return 0; }

} // namespace aoc2024

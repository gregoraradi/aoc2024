#include "day_01.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <regex>

namespace aoc2024 {

std::vector<char> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
std::uint32_t similarity_sum{0};

std::uint32_t Day_01::run(std::vector<std::string> const &data) {
  return part1(data);
}

std::uint32_t Day_01::part1(std::vector<std::string> const &data) {

  std::uint32_t cal_sum{};
  std::vector<std::uint32_t> lhs_loc_ids;
  std::vector<std::uint32_t> rhs_loc_ids;
  for (auto const &line : data) {

    std::regex rex("(\\d+)");
    auto number_first = std::sregex_iterator(line.begin(), line.end(), rex);
    auto number_last = std::sregex_iterator();
    bool even = true;
    for (std::sregex_iterator i = number_first; i != number_last; ++i) {
      std::smatch match = *i;
      std::string match_str = match.str();
      std::uint32_t match_uint = std::atoi(match_str.c_str());

      // std::cout << "  " << match_uint << '\n';

      if (even) {
        lhs_loc_ids.emplace_back(match_uint);
      } else {
        rhs_loc_ids.emplace_back(match_uint);
      }
      even = !even;
    }
  }

  std::sort(lhs_loc_ids.begin(), lhs_loc_ids.end());
  std::sort(rhs_loc_ids.begin(), rhs_loc_ids.end());

  std::vector<std::uint32_t> distances_loc_ids;

  for (auto i = 0U; i < lhs_loc_ids.size(); ++i) {
    std::int32_t lhs = lhs_loc_ids.at(i);
    std::int32_t rhs = rhs_loc_ids.at(i);

    auto diff = lhs - rhs;
    distances_loc_ids.emplace_back(std::abs(diff));
  }

  cal_sum =
      std::accumulate(distances_loc_ids.begin(), distances_loc_ids.end(), 0);

  // similarity
  std::vector<std::uint32_t> similarites;
  for (auto i = 0U; i < lhs_loc_ids.size(); ++i) {
    std::int32_t lhs = lhs_loc_ids.at(i);
    std::int32_t rhs = rhs_loc_ids.at(i);

    auto const cnt = std::count(rhs_loc_ids.begin(), rhs_loc_ids.end(), lhs);
    auto sim = lhs * cnt;
    similarites.emplace_back(sim);
  }

  similarity_sum = std::accumulate(similarites.begin(), similarites.end(), 0);

  return similarity_sum;
}

std::uint32_t Day_01::part2(std::vector<std::string> const &data) { return 0; }

} // namespace aoc2024

#include "day_02.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

namespace aoc2024 {

std::uint32_t Day_02::run(std::vector<std::string> const &data) {
  return part1(data);
}

bool is_safe_report(std::vector<std::int32_t> const &levels) {
  std::vector<std::int32_t> differences;
  std::adjacent_difference(levels.cbegin(), levels.cend(),
                           std::back_inserter(differences));

  // remove first element since it simply copies that one.
  differences.erase(differences.begin());

  auto increased =
      std::all_of(differences.begin(), differences.end(),
                  [](auto item) { return (item > 0 && item <= 3); });
  auto decreased =
      std::all_of(differences.begin(), differences.end(),
                  [](auto item) { return (item >= -3 && item < 0); });

  return (increased || decreased);
}

std::uint32_t Day_02::part1(std::vector<std::string> const &data) {
  std::uint32_t cal_sum{0};

  for (auto const &line : data) {
    std::cout << "line: " << line << std::endl;
    std::vector<std::int32_t> levels{};

    std::size_t start{};
    std::size_t end{};

    start = line.find_first_not_of(' ');
    while (start != std::string::npos) {

      end = line.find(' ', start);
      auto lvl = std::atoi(line.substr(start, end - start).c_str());
      levels.emplace_back(lvl);

      start = line.find_first_not_of(' ', end);
    }

    if (is_safe_report(levels)) {
      cal_sum += 1;
    } else {

      for (auto i = 0U; i < levels.size(); ++i) {
        std::vector<std::int32_t> cpy_levels;
        std::copy(levels.begin(), levels.end(), std::back_inserter(cpy_levels));

        auto it = cpy_levels.begin();
        std::advance(it, i);
        cpy_levels.erase(it);
        auto const usafe_to_safe_report = is_safe_report(cpy_levels);
        if (usafe_to_safe_report) {
          cal_sum += 1;
          break;
        }
      }
    }

    std::cout << "---" << std::endl;
  }

  return cal_sum;
}

std::uint32_t Day_02::part2(std::vector<std::string> const &data) { return 0; }

} // namespace aoc2024

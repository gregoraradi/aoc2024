#include "day_02.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string_view>

namespace aoc2024 {

std::uint32_t Day_02::run(std::vector<std::string> const &data) {
  return part1(data);
}

std::uint32_t Day_02::part1(std::vector<std::string> const &data) {
  std::uint32_t cal_sum{0};

  for (auto const &line : data) {
    std::cout << "line: " << line << std::endl;
    std::vector<std::int32_t> levels{};
    std::vector<std::int32_t> differences{};

    std::size_t start{};
    std::size_t end{};

    start = line.find_first_not_of(' ');
    while (start != std::string::npos) {

      end = line.find(' ', start);
      auto lvl = atoi(line.substr(start, end - start).c_str());
      levels.emplace_back(lvl);

      start = line.find_first_not_of(' ', end);
    }

    differences.resize(levels.size());
    std::adjacent_difference(levels.begin(), levels.end(), differences.begin());

    // Verify
    differences.erase(differences.begin());
    for (auto it = differences.begin(); it != differences.end(); ++it) {
      //   if (it == differences.begin()) {
      //     continue;
      //   }
      std::cout << *it << " " << std::endl;
    }

    auto increased =
        std::all_of(differences.begin(), differences.end(),
                    [](auto item) { return (item > 0 && item <= 3); });
    auto decreased =
        std::all_of(differences.begin(), differences.end(),
                    [](auto item) { return (item >= -3 && item < 0); });
    cal_sum += (increased || decreased) ? 1 : 0;
    // if (increased || decreased) {
    //   std::cout << ">>safe" << std::endl;
    // }

    if (!increased && !decreased) {

      auto const count_neg =
          std::count_if(differences.begin(), differences.end(),
                        [](auto item) { return (item < 0); });

      auto const count_neg_less =
          std::count_if(differences.begin(), differences.end(),
                        [](auto item) { return (item < -3); });

      auto const count_pos =
          std::count_if(differences.begin(), differences.end(),
                        [](auto item) { return (item > 0); });

      auto const count_pos_high =
          std::count_if(differences.begin(), differences.end(),
                        [](auto item) { return (item > 3); });

      auto const count_zero =
          std::count_if(differences.begin(), differences.end(),
                        [](auto item) { return (item == 0); });

      if ((count_pos_high >= 1 && (differences.back() > 3)) ||
          (count_neg_less >= 1 && (differences.front() < -3))) {
        std::cout << ">>unsafe!" << std::endl;
      } else {
        if (count_pos > count_neg) {
          if ((count_neg + count_zero) == 1) {
            std::cout << ">>unsafe to safe" << std::endl;
            ++cal_sum;
          }
        }

        if (count_neg > count_pos) {
          if ((count_pos + count_zero) == 1) {
            std::cout << ">>unsafe to safe" << std::endl;
            ++cal_sum;
          }
        }
      }
    }
    std::cout << "---" << std::endl;
  }

  return cal_sum;
}

std::uint32_t Day_02::part2(std::vector<std::string> const &data) { return 0; }

} // namespace aoc2024

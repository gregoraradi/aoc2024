#include "day_04.hpp"
#include <algorithm>
#include <format>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <tuple>

namespace aoc2024 {

std::uint32_t Day_04::run(std::vector<std::string> const &data) {
  // return part2(data);
  return part1(data);
}

std::uint32_t Day_04::part1(std::vector<std::string> const &data) {

  std::uint32_t sum{0};
  std::uint32_t h_found{};
  std::uint32_t h_found_rev{};
  std::uint32_t v_found{};
  std::uint32_t v_found_rev{};
  std::uint32_t diag_found{};
  std::uint32_t diag_found_rev{};
  std::uint32_t diag_found_2{};
  std::uint32_t diag_found_2_rev{};
  std::uint32_t const rows = data.size();
  std::uint32_t const columns = data[0].size();

  std::string const h_xmas{"XMAS"};
  std::string const h_xmas_rev{"SAMX"};
  // for (auto const &line : data) {

  auto const check_horizontal = [&columns](auto c, auto r, auto search,
                                           auto const &data) -> bool {
    bool found_horizontal{false};
    auto const &xmas = search;
    if ((c + xmas.size() - 1) >= columns) {
      return false;
    }
    auto const &line = data[r];
    for (auto x = 0; x < xmas.size(); ++x) {
      if (line.at(c + x) == xmas.at(x)) {
        found_horizontal = true;
      } else {
        found_horizontal = false;
        break;
      }
    }
    return found_horizontal;
  };

  auto const check_vertical = [&columns, &rows](auto c, auto r, auto search,
                                                auto const &data) -> bool {
    bool found_vertical{false};
    auto const &xmas = search;
    if ((r + xmas.size() - 1) >= rows) {
      return false;
    }

    for (auto x = 0; x < xmas.size(); ++x) {
      if (data.at(r + x).at(c) == xmas.at(x)) {
        found_vertical = true;
      } else {
        found_vertical = false;
        break;
      }
    }
    return found_vertical;
  };

  auto check_diagonal = [&columns, &rows](auto c, auto r, auto const &search,
                                          auto const &data) -> bool {
    bool found_diag{false};
    auto const &xmas = search;
    if ((c + xmas.size()) > columns || (r + xmas.size()) > rows) {
      return false;
    }
    for (auto x = 0; x < xmas.size(); ++x) {
      auto data_row = data.at(r + x);

      if (data_row[c + x] == xmas[x]) {
        found_diag = true;
      } else {
        found_diag = false;
        break;
      }
    }
    return found_diag;
  };

  auto const check_diagonal2 = [&columns, &rows](auto c, auto r,
                                                 auto const &search,
                                                 auto const &data) -> bool {
    bool found_diag{false};
    auto const &xmas = search;
    if ((c < (xmas.size() - 1)) || (r + xmas.size()) > rows) {
      return false;
    }
    for (auto x = 0; x < xmas.size(); ++x) {
      auto data_row = data.at(r + x);
      if (data_row[c - x] == xmas[x]) {
        found_diag = true;
      } else {
        found_diag = false;
        break;
      }
    }
    if (found_diag) {
      std::cout << "r/c: " << r << "/" << c << std::endl;
    }
    return found_diag;
  };

  // horizontal xmas
  for (auto r = 0; r < rows; ++r) {
    for (auto c = 0; c < columns;) {
      // check for xmas
      auto const found = check_horizontal(c, r, h_xmas, data);
      if (found) {
        ++h_found;
        c += h_xmas.size();
      } else {
        ++c;
      }
    }
  }

  // horizontal samx
  for (auto r = 0; r < rows; ++r) {
    for (auto c = 0; c < columns;) {
      // check for xmas
      auto const found_rev = check_horizontal(c, r, h_xmas_rev, data);
      if (found_rev) {
        ++h_found_rev;
        c += h_xmas_rev.size();
      } else {
        ++c;
      }
    }
  }

  // vertical xmas
  for (auto r = 0; r < rows; ++r) {
    for (auto c = 0; c < columns; ++c) {
      // check for xmas
      auto const found = check_vertical(c, r, h_xmas, data);
      if (found) {
        ++v_found;
        // r += h_xmas_rev.size();
      }
    }
  }
  // vertical samx
  for (auto r = 0; r < rows; ++r) {
    for (auto c = 0; c < columns; ++c) {
      // check for xmas
      auto const found = check_vertical(c, r, h_xmas_rev, data);
      if (found) {
        ++v_found_rev;
        // r += h_xmas_rev.size();
      }
    }
  }

  // vertical diag xmas left-top to right-bottom
  for (auto r = 0; r < rows; ++r) {
    for (auto c = 0; c < columns; ++c) {
      // check for xmas
      auto const found = check_diagonal(c, r, h_xmas, data);
      if (found) {
        ++diag_found;
      }
    }
  }

  // vertical diag samx left-top to right-bottom
  for (auto r = 0; r < rows; ++r) {
    for (auto c = 0; c < columns; ++c) {
      // check for xmas
      auto const found = check_diagonal(c, r, h_xmas_rev, data);
      if (found) {
        ++diag_found_rev;
      }
    }
  }

  // vertical diag xmas right-top to left-bottom
  for (auto r = 0; r < rows; ++r) {
    for (auto c = 0; c < columns; ++c) {
      // check for xmas
      auto const found = check_diagonal2(c, r, h_xmas, data);
      if (found) {
        ++diag_found_2;
      }
    }
  }
  // vertical diag samx right-top to left-bottom
  for (auto r = 0; r < rows; ++r) {
    for (auto c = 0; c < columns; ++c) {
      // check for xmas
      auto const found = check_diagonal2(c, r, h_xmas_rev, data);
      if (found) {
        ++diag_found_2_rev;
      }
    }
  }

  std::vector<std::uint32_t> single_sums{
      h_found,    h_found_rev,    v_found,      v_found_rev,
      diag_found, diag_found_rev, diag_found_2, diag_found_2_rev};
  sum = std::accumulate(single_sums.begin(), single_sums.end(), 0);

  std::cout << "h found: " << h_found << std::endl;
  std::cout << "r h found: " << h_found_rev << std::endl;
  std::cout << "v found: " << v_found << std::endl;
  std::cout << "r v found: " << v_found_rev << std::endl;
  std::cout << "diag found: " << diag_found << std::endl;
  std::cout << "r diag found: " << diag_found_rev << std::endl;
  std::cout << "diag 2 found: " << diag_found_2 << std::endl;
  std::cout << "r diag 2 found: " << diag_found_2_rev << std::endl;

  return sum;
}

std::uint32_t Day_04::part2(std::vector<std::string> const &data) {
  std::uint32_t sum{0};
  return sum;
}

} // namespace aoc2024

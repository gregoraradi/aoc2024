#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <string>

#include "days/day_01.hpp"
#include "days/day_02.hpp"
#include "days/day_03.hpp"
#include "days/day_04.hpp"
#include "filereader.hpp"
#include "logger.hpp"

std::string full_filepath(std::string const &path, std::string const &file) {
  return (path + "/res/" + file);
}

std::string full_filepath_by_day(std::string const &path, std::uint32_t day,
                                 std::uint32_t example = 0U) {
  std::stringstream ss;
  ss << path << "/res/day_";
  if (day < 10) {
    ss << "0";
  }
  if (example > 0U) {
    ss << "_" << example;
  }
  ss << day << ".txt";
  return ss.str();
}

int main() {
  {
    Filereader fr{};
    auto filename = full_filepath(WORKSPACE, "day_04.txt");
    auto result = fr.get_data_linewise(filename);

    aoc2024::Day_04 day;
    auto const day_result = day.run(std::get<0>(result));

    aoc2024::logger::log_puzzle_sum(4, day_result);
  }

  return 0;
}

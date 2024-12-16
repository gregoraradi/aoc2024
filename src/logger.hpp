#pragma one

#include <cstdint>
#include <format>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>

namespace aoc2024 {
namespace logger {

static void log(std::string const &s) { std::cout << s << std::endl; }
static void log(std::stringstream const &ss) {
  std::cout << ss.str() << std::endl;
}

static void log_puzzle_sum(std::uint32_t day, std::uint32_t sum) {
  auto const fmt = std::format("Puzzle Day #{} sum: {}", day, sum);
  log(fmt);
}

} // namespace logger
} // namespace aoc2024

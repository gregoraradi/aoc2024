#ifndef aoc2024_DAY_01_HPP
#define aoc2024_DAY_01_HPP

#include <cstdint>
#include <string>
#include <vector>

namespace aoc2024 {
class Day_01 {
public:
  Day_01() = default;

  std::uint32_t run(std::vector<std::string> const &data);

private:
  std::uint32_t part1(std::vector<std::string> const &data);
  std::uint32_t part2(std::vector<std::string> const &data);
};

} // namespace aoc2024
#endif // aoc2024_DAY_01_HPP

#ifndef aoc2024_FILEREADER_HPP
#define aoc2024_FILEREADER_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using Filereader_data = std::vector<std::string>;
using Filereader_result = std::pair<Filereader_data, bool>;

class Filereader {
public:
  Filereader() = default;

  Filereader_result get_data_linewise(std::string const &filename) {
    Filereader_data data{};
    bool error{false};
    std::ifstream ifs;

    ifs.open(filename);
    if (!ifs.is_open()) {
      error = true;
      return std::make_pair(data, error);
    }

    char delim{'\n'};
    std::string line;
    while (std::getline(ifs, line, delim)) {
      data.push_back(line);
    }

    ifs.close();

    return std::make_pair(std::move(data), error);
  }
};

#endif // aoc2024_FILEREADER_HPP

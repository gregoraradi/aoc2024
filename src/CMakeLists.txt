
set(WORKSPACE "${CMAKE_SOURCE_DIR}")
add_compile_definitions(WORKSPACE="${WORKSPACE}")

add_executable(aoc2024
  days/day_01.cpp
  days/day_02.cpp
  days/day_03.cpp
  days/day_04.cpp
  main.cpp
)

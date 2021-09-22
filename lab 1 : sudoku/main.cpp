#define CATCH_CONFIG_MAIN
#include "Sudoku.h"
#include "catch.hpp"
#include <sstream>

TEST_CASE("find") {
  int arr[SIZE * SIZE] = {5, 3, 0, 0, 7, 0, 0, 0, 0, 6, 0, 0, 1, 9, 5, 0, 0,
                          0, 0, 9, 8, 0, 0, 0, 0, 6, 0, 8, 0, 0, 0, 6, 0, 0,
                          0, 3, 4, 0, 0, 8, 0, 3, 0, 0, 1, 7, 0, 0, 0, 2, 0,
                          0, 0, 6, 0, 6, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 4, 1,
                          9, 0, 0, 5, 0, 0, 0, 0, 8, 0, 0, 7, 9};

  ds::Sudoku puzzle(arr);
  puzzle.solve();

  std::stringstream ss;
  puzzle.print(ss);
  CHECK(ss.str() == "5 3 4 6 7 8 9 1 2\n"
                    "6 7 2 1 9 5 3 4 8\n"
                    "1 9 8 3 4 2 5 6 7\n"
                    "8 5 9 7 6 1 4 2 3\n"
                    "4 2 6 8 5 3 7 9 1\n"
                    "7 1 3 9 2 4 8 5 6\n"
                    "9 6 1 5 3 7 2 8 4\n"
                    "2 8 7 4 1 9 6 3 5\n"
                    "3 4 5 2 8 6 1 7 9");
}

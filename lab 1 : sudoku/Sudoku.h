#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#include <ostream>

namespace ds {

#define SIZE 9

class Sudoku {
private:
  int grid[SIZE][SIZE];

public:
  /**
   * Construct a new Sudoku object
   * DO NOT change this function.
   *
   * @param board The grid in 1D.
   */
  Sudoku(int *board) {
    for (int row = 0; row < SIZE; row++) {
      for (int col = 0; col < SIZE; col++) {
        this->grid[row][col] = board[row * SIZE + col];
      }
    }
  }

  /**
   * Print the grid in 1D.
   * DO NOT change this function.
   */
  void print(std::ostream &os) const {
    for (int row = 0; row < SIZE; row++) {
      if (row != 0)
        os << "\n";
      for (int col = 0; col < SIZE; col++) {
        if (col != 0)
          os << " ";
        os << grid[row][col];
      }
    }
  }

  void solve();
};

} // namespace ds

#endif // __SUDOKU_H__

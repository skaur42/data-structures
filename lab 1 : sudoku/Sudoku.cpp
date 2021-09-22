#include "Sudoku.h"

namespace ds {

bool isValid(int grid[9][9], int i, int j, int n) {
  // Check the validness of n if placed in grid[i][j].
  // It returns false if row i of grid contains n,
  //    returns false if column j of grid contains n,
  //    returns false if subgrid of i and j contains n,
  //    and returns true otherwise.
  for(int x = 0; x <= 8; x++){
    if(grid[i][x] == n) 
      return false;
  }
  for(int x = 0; x <= 8; x++){
    if(grid[x][j] == n)
      return false;
  }

  int substart = i - i % 3;
  int subend = j - j % 3;
  for (int a = 0; a < 3; a++){
    for (int b = 0; b < 3; b++){
      if (grid[a + substart][b + subend] == n)
        return false;
    }
  }

  return true;

}
  
// return true if placement results in final solution of puzzle
// return false otherwise
bool backtrack(int grid [9][9], int i, int j){
  // return true when all 81 cells are complete 
  if(i > 8)
    return true;

  // at the end of a row, continue exploration
  // on the first element of the next row
  if (j > 8)
    return backtrack(grid, i+1, 0);
    
  // continue exploration when grid is not empty
  if(grid[i][j] != 0)
    return backtrack(grid, i, j+1);

  for(int n = 1; n <= 9; n++) { // try to place 1-9
    if(isValid(grid, i, j, n)){ // if n is valid
      grid[i][j] = n; // place n
      if (backtrack(grid, i, j+1)) { // try to place a number in the next cell
        return true; // find a solution
      }
      grid[i][j] = 0; // if we didn't find a solution, backtrack by resetting the placement of n and try the next number
    }
  }
  return false; // all numbers 1-9 failed to solve the puzzle (since would've returned true if there's a solution)
}

/**
 * Solve the sudoku puzzle by setting 1-9 to cells in `this->grid`.
 * Note: 0 indicates an empty cell.
 */
void Sudoku::solve() {
  backtrack(this->grid, 0, 0);
}

} // namespace ds

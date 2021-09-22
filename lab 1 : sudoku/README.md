# Lab 1: Sudoku Solver

In this lab, I implemented a solver for [Sudoku puzzles](https://en.wikipedia.org/wiki/Sudoku).

## 1. The Sudoku Problem

As introduced on the [Wikipedia page](https://en.wikipedia.org/wiki/Sudoku):

> Sudoku (数独, sūdoku, digit-single) (/suːˈdoʊkuː/, /-ˈdɒk-/, /sə-/, originally called Number Place) is a logic-based, combinatorial number-placement puzzle. In classic sudoku, the objective is to fill a 9×9 grid with digits so that each column, each row, and each of the nine 3×3 subgrids that compose the grid (also called "boxes", "blocks", or "regions") contain all of the digits from 1 to 9. The puzzle setter provides a partially completed grid, which for a well-posed puzzle has a single solution.

## 2. Solving the puzzle

The Sudoku solution satisfies all of the following rules:

- Each of the digits `1` to `9` must occur exactly once in each row of `grid`
- Each of the digits `1` to `9` must occur exactly once in each column of `grid`
- Each of the digits `1` to `9` must occur exactly once in each of the **nine** 3x3 subgrids of `grid`

The `0` in `grid` indicates empty cells. The solution should not have `0` in it.

Implemented **backtracking** to solve the given puzzle.
Assume that the input board has only one solution.

Description of the backtracking algorithm [here](https://en.wikipedia.org/wiki/Sudoku_solving_algorithms).

## 3. Build and test

A sample test case is given in [main.cpp](main.cpp).

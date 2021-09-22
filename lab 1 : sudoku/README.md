# Lab 6: Sudoku Solver

![Due: Apr 16 11:59PM](https://img.shields.io/badge/Due-Apr_16_11:59PM-orange)
![Points badge](../../blob/badges/points.svg)

In this lab, you will implement a solver for [Sudoku puzzles](https://en.wikipedia.org/wiki/Sudoku).

## 1. Clone repository

To clone the remote repository to local machine, run the following commands:

```bash
cd SOME_DIRECTORY # any arbitrary folder you'd like to your code in
git clone https://github.com/cisc2200/lab6-sp21-YOUR_GITHUB_ID.git
cd lab6-sp21-YOUR_GITHUB_ID
```

## 2. The Sudoku Problem

As introduced on the [Wikipedia page](https://en.wikipedia.org/wiki/Sudoku):

> Sudoku (数独, sūdoku, digit-single) (/suːˈdoʊkuː/, /-ˈdɒk-/, /sə-/, originally called Number Place) is a logic-based, combinatorial number-placement puzzle. In classic sudoku, the objective is to fill a 9×9 grid with digits so that each column, each row, and each of the nine 3×3 subgrids that compose the grid (also called "boxes", "blocks", or "regions") contain all of the digits from 1 to 9. The puzzle setter provides a partially completed grid, which for a well-posed puzzle has a single solution.

## 3. Solving the puzzle

A valid Sudoku solution must satisfy all of the following rules:

- Each of the digits `1` to `9` must occur exactly once in each row of `grid`
- Each of the digits `1` to `9` must occur exactly once in each column of `grid`
- Each of the digits `1` to `9` must occur exactly once in each of the **nine** 3x3 subgrids of `grid`

The `0` in `grid` indicates empty cells. The solution should not have `0` in it.

You will use **backtracking** to solve the given puzzle.
You need to complete the `solve` function in [Sudoku.cpp](Sudoku.cpp#L10) by setting the cells in `grid`.
You can assume that the input board has only one solution.

You can find the description of the backtracking algorithm [here](https://en.wikipedia.org/wiki/Sudoku_solving_algorithms).

## 4. Build and test

A sample test case is given in [main.cpp](main.cpp). You can modify its content to create your own tests. But it will not be used for grading and should not be committed.

The local repository must first be opened in a Docker container to run tests. In VS Code, click on the "><" button in the bottom-left corner and then select *"Remote-Containers: Reopen in Container"* to open the local repository in a container.
**To get the full-fledged C++ dev environment (including autocompletion, formatting, etc.), you need to install the `clangd` language server when a dialog is prompted.**
Next, in the [integrated terminal](https://code.visualstudio.com/docs/editor/integrated-terminal), run the following command to compile and run the code:

```bash
make clean test # the compilation takes time; please be patient
```

## 5. Commit and push

```bash
git add Sudoku.cpp # stage your changes locally
git commit -m "add solve" # commit the changes to local repo; the message is for your record and could be arbitrary
git push # push the local commit to GitHub
```

Please refer to the `README.md` file from Lab 1 for more instructions.

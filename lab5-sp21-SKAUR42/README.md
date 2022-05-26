# Lab 5: Binary Search

![Due: Apr 2 11:59PM](https://img.shields.io/badge/Due-Apr_2_11:59PM-orange)
![Points badge](../../blob/badges/points.svg)

In this lab, you will finish the `findInsertPosition` function in [`find.cpp`](find.cpp). Your implementation should be based on the **binary search** algorithm.

There are 5 test cases in total and 0.6 pts for each test case.
We will manually look at your code to check if you follow the binary search algorithm. If not, your grade will be reduced by *1 pt*.

## 1. Clone repository

The main files in the repository are

- `find.cpp`: where the `findInsertPosition` function resides
- `SortedList.h`: base class for sorted list
- `SortedAList.h`: sorted list based on arrays
- `main.cpp`: the test case; entry of program

You are expected to modify `find.cpp`. If you change the content of other files, **DO NOT** commit and push them to GitHub.

To clone the remote repository to local machine, run the following commands:

```bash
cd SOME_DIRECTORY
git clone https://github.com/cisc2200/lab5-sp21-YOUR_GITHUB_ID.git
cd lab5-sp21-YOUR_GITHUB_ID
```

## 2. Find insert position

You should complete the `findInsertPosition` function in [`find.cpp`](find.cpp). Given a sorted list and a target value `target`, your implementation should **return the position if the target is found**. If not, it should **return the index where the target would be if it were inserted in order**. You may assume no duplicates in the list.

For example, if we have `l=[1,3,5,6]` and `target=5`, the return value should be `2`.
The return value should be `1` if `target=2`, `4` if `target=7`, and `0` if `target=0`.

**Note:** The implementation must apply the **binary search** algorithm.

## 3. Build and test

A sample test case is given in [main.cpp](main.cpp). You can modify its content to create your own tests. But it will not be used for grading and should not be committed.

The local repository must first be opened in a Docker container to run tests. In VS Code, click on the "><" button in the bottom-left corner and then select *"Remote-Containers: Reopen in Container"* to open the local repository in a container.
**To get the full-fledged C++ dev environment (including autocompletion, formatting, etc.), you need to install the `clangd` language server when a dialog is prompted.**
Next, in the [integrated terminal](https://code.visualstudio.com/docs/editor/integrated-terminal), run the following command to compile and run the code:

```bash
make clean test # the compilation takes time; please be patient
```

If your code passed the test case, you would see the output like the following:

```
===============================================================================
All tests passed (2 assertions in 2 test case)

...... (details about memory use omitted)

==480== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

You can also modify `main.cpp` to add more test cases, but they will not be used for grading.

## 4. Commit and push

```bash
git add find.cpp # stage your changes locally
git commit -m "add findInsertPosition" # commit the changes to local repo; the message is for your record and could be arbitrary
git push # push the local commit to GitHub
```

Please refer to the `README.md` file from Lab 1 for more instructions.

# Lab 7: BSTMap

![Due: Apr 23 11:59PM](https://img.shields.io/badge/Due-Apr_23_11:59PM-orange)
![Points badge](../../blob/badges/points.svg)

In this lab, you need to complete the `BSTMap` class, a `map` structure based on Binary Search Trees (BST). You will implement the `get` and `remove` functions.

## 1. Clone repository

To clone the remote repository to local machine, run the following commands:

```bash
cd SOME_DIRECTORY # any arbitrary folder you'd like to put the code in
git clone https://github.com/cisc2200/lab7-sp21-YOUR_GITHUB_ID.git
cd lab7-sp21-YOUR_GITHUB_ID
```

We discussed the `find` and `insert` functions for regular `BST` (which implements `Set`) in details in class, as well as the algorithm for `remove`.
The code of `find` and `put` functions are provided in `BSTMap`, and you need to implement the `get` and `remove`.

**Note:** `BSTPrinter.h` is the helper class for printing of a `BST` and you should not change its content.

## 2. Get the value in BSTMap given a key

The function `get` in [BSTMap.h](BSTMap.h#L103) returns the value of a given search key in the `BSTMap`. For example, suppose we have a map `m = {"sumomo": 1, "momo": 2, "uchi": 1, "mo": 2, "no": 2}`. A call to `m.get("momo")` should return `2` and a call to `m.get("uchi")` will return `1`.

**Tips:**
You need to create a private recursive function, e.g. `getHelp` for the `get` function. You can look at `findHelp` and `putHelp` for inspiration. Avoid "arms length base cases", i.e., don’t check if left or right is null!


## 3. Remove a key-value pair from the BSTMap given a key

The function `remove` in [BSTMap.h](BSTMap.h#L111) deletes the key-value pair in the `BSTMap` given a key. For example, suppose we have a map `m = {"sumomo": 1, "momo": 2, "uchi": 1, "mo": 2, "no": 2}`. A call to `m.remove("momo")` should remove the pair `"momo": 2` and the resulting `m = {"sumomo": 1, "uchi": 1, "mo": 2, "no": 2}`. Another call to `m.remove("uchi")` will remove the pair `"uchi": 1` and make `m = {"sumomo": 1, "mo": 2, "no": 2}`.

**Requirements:**
In class, we discussed the `remove` algorithm for 3 cases.
In this lab, you should promote the **successor** for the 3rd case when a node has two children.
The autograder will mark implementations promoting the predecessor as incorrect.

**Tips:**
You need to create a private recursive function, e.g. `removeHelp`.

## 4. Build and test

A sample test case is given in [main.cpp](main.cpp). You can modify its content to create your own tests. But it will not be used for grading and should not be committed.

The local repository must first be opened in a Docker container to run tests. In VS Code, click on the "><" button in the bottom-left corner and then select *"Remote-Containers: Reopen in Container"* to open the local repository in a container.
**To get the full-fledged C++ dev environment (including autocompletion, formatting, etc.), you need to install the `clangd` language server when a dialog is prompted and reload the window.**
Next, in the [integrated terminal](https://code.visualstudio.com/docs/editor/integrated-terminal), run the following command to compile and run the code:

```bash
make clean test # this takes time; please be patient
```

## 5. Commit and push

```bash
git add BSTMap.h # stage your changes locally
git commit -m "add get and remove" # commit the changes to local repo; the message is for your record and could be arbitrary
git push # push the local commit to GitHub
```

Please refer to the `README.md` file from Lab 1 for more instructions.

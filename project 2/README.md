# Proj 2: Basic calculator for `BigInt`

![Due: Apr 9 11:59PM](https://img.shields.io/badge/Due-Apr_9_11:59PM-orange)
![Points badge](../../blob/badges/points.svg)

In this project, you will implement a basic calculator for `BigInt` from Proj 1 that computes the result of an infix expression. You can find more details in the following sections.

Your code should have sufficient comments and is properly indented. The score will depend on the autograding results (10 test cases, 4 pts in total) and your code quality (4 pts; we will manually check your code).

**NEW:** As the deadline approaches, more hints will be revealed on Piazza to help you solve the problems. You will get bonus extra credit if you submit before hints are all released.
Specifically, if you submit before **Mar 30 11:59 PM**, you will get **1 pt** as extra credit. If you submit before **Apr 6 11:59 PM**, you will get **0.5 pts** as extra credit.


## 1. Clone repository

To clone the remote repository to local machine, run the following commands in terminal:

```bash
cd SOME_DIRECTORY
git clone https://github.com/cisc2200/proj2-sp21-YOUR_GITHUB_ID.git
cd proj2-sp21-YOUR_GITHUB_ID
```

This project uses a new `List` class `VList` which is based on the built-in `std::vector` class. Just like `AList` and `SLList`, `VList` supports functions such as `addFirst`, `addLast`, `getFirst`, `getLast`, `removeFirst`, `removeLast`, `get(i)`, `remove(i)`, and so on. **Note that you are users of the class and don't have to know the details of the implementation.**

The `operator+` and `operator-` of `BigInt` have been implemented and packaged into a library `libbigint.a`. It also contains the operations for comparing two `BigInt`s (see [BigInt.h](BigInt.h)). **Again, you can assume the implementation is correct and don't have to know the details.**

The **ONLY** file that you need to add your code in is [Calculator.cpp](Calculator.cpp). You will complete two functions: `infixToPostfix` and `evaluatePostfix` in this file. You may find examples of using these functions in [main.cpp](main.cpp).

## 2. Infix to postfix

The input of function `infixToPostfix` is an expression using [infix notation](https://en.wikipedia.org/wiki/Infix_notation) that may contain `(`, `)`, `+`, `-`, digits, and white spaces ("` `", "`\t`", "`\n`", etc.).
For example, `23543 + ( 345 - 123)`.

Your implementation should transform the infix expression to its corresponding ***postfix expression*** using the [reverse Polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation).
The syntax of postfix expression requires that the two operands are specified first, followed by the operator: `operand1 operand2 operator`. For example, `23543 345 123 - +` means `23543 + (345 - 123)`.

**HINT#1:** You can refer to [this link](http://www.cplusplus.com/reference/string/string/) for the `std::string` class, for example, to find out how to access each `char` in the string object.

**HINT#2:** You can use [`isspace`](https://en.cppreference.com/w/cpp/string/byte/isspace) to check if a character is any kind of white space.

**HINT#3:** You should use the [`std::stack` class](http://www.cplusplus.com/reference/stack/stack/) in the implementation to record intermediate results.


## 3. Evaluate postfix expressions

The input of function `evaluatePostfix` is a ***postfix expression***. Your implementation should **evaluate** the expression and **return** the final result as a `BigInt`.
You should create one `BigInt` object for each operand and use the functions in `BigInt` class for the evaluation.

**HINT:** Below is the skeleton of the evaluation algorithm:

1. Declare a stack of `BigInt` to store the operands and the value of the subexpression
2. Scan the expression from left to right
    1) If the `char` is a white space, skip to the next `char`.
    2) If the `char` is a digit, continue reading until a non-digit `char` is observed, create a `BigInt` object for the substring, and push the `BigInt` into the stack.
    3) if the `char` is an operation symbol (`+`, `-`), pop two elements from the stack and apply the operation on the two elements, push the result onto the stack.
    4) When reaching the end of the expression, there should be only one value in the stack that is the result of the whole expression. Return this value.

## 4. Build and test

An example test is given in [main.cpp](main.cpp). You could modify its content to create your own tests.
To run the test, you need to open the local repository in a Docker container. To do this, in VS Code, click on the "><" button in the bottom-left corner and then select *"Remote-Containers: Reopen in Container"*. Next, in the [terminal](https://code.visualstudio.com/docs/editor/integrated-terminal), run the following command:

```bash
make clean test # it takes time; please be patient
```

You should also add more test cases to ensure your implementation behaves correctly. You could use online [big number calculator](https://www.calculator.net/big-number-calculator.html) for verification.

## 5. Commit and push

```bash
git add Calculator.cpp # stage your changes locally
git commit -m "add infix to postfix and eval" # commit the changes to local repo; the message is for your record and could be arbitrary
git push # push the local commit to GitHub
```

Please refer to the readme file in Lab 1 for more instructions on `git`.

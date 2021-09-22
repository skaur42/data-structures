# Proj 2: Basic calculator for `BigInt`

In this project, I implemented a basic calculator for `BigInt` that computes the result of an infix expression. More details are provided  in the following sections.


This project uses a new `List` class `VList` which is based on the built-in `std::vector` class. Just like `AList` and `SLList`, `VList` supports functions such as `addFirst`, `addLast`, `getFirst`, `getLast`, `removeFirst`, `removeLast`, `get(i)`, `remove(i)`, and so on. 

The `operator+` and `operator-` of `BigInt` have been implemented and packaged into a library `libbigint.a`. It also contains the operations for comparing two `BigInt`s (see [BigInt.h](BigInt.h)).


## 1. Infix to postfix

The input of function `infixToPostfix` is an expression using [infix notation](https://en.wikipedia.org/wiki/Infix_notation) that may contain `(`, `)`, `+`, `-`, digits, and white spaces ("` `", "`\t`", "`\n`", etc.).
For example, `23543 + ( 345 - 123)`.

The implementation transforms the infix expression to its corresponding ***postfix expression*** using the [reverse Polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation).
The syntax of postfix expression requires that the two operands are specified first, followed by the operator: `operand1 operand2 operator`. For example, `23543 345 123 - +` means `23543 + (345 - 123)`.


## 2. Evaluate postfix expressions

The input of function `evaluatePostfix` is a ***postfix expression***. The implementation evaluates the expression and returns the final result as a `BigInt`.
Created one `BigInt` object for each operand and used the functions in `BigInt` class for the evaluation.


## 3. Build and test

An example test is given in [main.cpp](main.cpp). 
To run the test, you need open the local repository in a Docker container. 

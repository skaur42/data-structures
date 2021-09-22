# Lab 3: Singly Linked List

`SLList` class with **sentinel node** is a generalized version of the [singly linked list class] [templates](https://www.cplusplus.com/doc/oldtutorial/templates/).

The files in the repository are

- `Node.h`: the definition of the `Node` class
- `SLList.h`: the definition of the `SLList` class
- `main.cpp`: the test case; entry of program

## 1. The copy constructor and destructor

Implemented a version of the [`SLList(const SLList &other)`](SLList.h#L68) and [`~SLList()`](SLList.h#L74) methods.
The copy constructor deep-copies the `other` list.
The destructor deletes all nodes in the list, including the sentinel node.

## 2. Retrieve the i-th item in list

The `get(i)` method in [SLList.h](SLList.h#L80) returns the i-th item in the list. For example, given a list `L=[5,10,15]`. Calling `get(0)` on `L` should return `5`, while `get(1)` and `get(2)` should return `10` and `15`, respectively. **Assume the item always exists**


## 3. Remove the first/last item in list

Method [`removeFirst`](SLList.h#L86) and [`removeLast`](SLList.h#L92) are used to **remove and return** the first and last elements in a list. For example, given a list `L=[1,2,3,4]`, `L.removeFirst()` deletes and returns the first item `1` in `L`. The resulting `L` is now `[2,3,4]`. Calling `L.removeLast()` deletes and returns the last item `4` in `L` and `L` now becomes `[2,3]`. **Assume the first/last item always exists.**

## 4. Build and test

A sample test case is given in [main.cpp](main.cpp).

# Lab 2: BSTMap

The `BSTMap` class is a `map` structure based on Binary Search Trees (BST).

## 1. Get the value in BSTMap given a key

The function `get` in [BSTMap.h](BSTMap.h#L103) returns the value of a given search key in the `BSTMap`. For example, suppose we have a map `m = {"sumomo": 1, "momo": 2, "uchi": 1, "mo": 2, "no": 2}`. A call to `m.get("momo")` should return `2` and a call to `m.get("uchi")` will return `1`.
Created a private recursive function, e.g. `getHelp` for the `get` function.


## 2. Remove a key-value pair from the BSTMap given a key

The function `remove` in [BSTMap.h](BSTMap.h#L111) deletes the key-value pair in the `BSTMap` given a key. For example, suppose we have a map `m = {"sumomo": 1, "momo": 2, "uchi": 1, "mo": 2, "no": 2}`. A call to `m.remove("momo")` removes the pair `"momo": 2` and the resulting `m = {"sumomo": 1, "uchi": 1, "mo": 2, "no": 2}`. Another call to `m.remove("uchi")` will remove the pair `"uchi": 1` and make `m = {"sumomo": 1, "mo": 2, "no": 2}`.


## 3. Build and test

A sample test case is given in [main.cpp](main.cpp). 

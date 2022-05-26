#define CATCH_CONFIG_MAIN
#include "SortedAList.h"
#include "catch.hpp"
#include <sstream>

int findInsertPosition(ds::SortedList<int> &list, int target);

TEST_CASE("find") {
  int arr[5];
  for (int i = 0; i < 5; i++) {
    arr[i] = i + 1;
  }
  ds::SortedAList<int> L(arr, 5);
  CHECK(findInsertPosition(L, 3) == 2);
  CHECK(findInsertPosition(L, 8) == 5);
}

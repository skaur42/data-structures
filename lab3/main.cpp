#define CATCH_CONFIG_MAIN
#ifdef DEBUG
#include "SLListImpl.h"
#else
#include "SLList.h"
#endif
#include "catch.hpp"
#include <cstdlib>

#define SIZE 10

TEST_CASE("All") {
  ds::SLList<int> L;

  // randomly add SIZE ints to the array
  int nums[SIZE];
  srand(time(0)); // setting the seed for rand()
  for (int i = SIZE - 1; i >= 0; i--) {
    nums[i] = rand() % 20 + 1; // generating random numbers by rand()
    L.addFirst(nums[i]);
  }

  SECTION("get") {
    CHECK(L.get(0) == nums[0]);
    CHECK(L.get(SIZE - 1) == nums[SIZE - 1]);
  }

  SECTION("copy constructor") {
    ds::SLList<int> *K = new ds::SLList<int>(L);
    CHECK(L.size() == K->size());
    CHECK(K->get(0) == nums[0]);
    CHECK(K->get(SIZE - 1) == nums[SIZE - 1]);
    delete K; // this should not also delete L
  }

  SECTION("removeFirst") {
    CHECK(nums[0] == L.removeFirst());
    CHECK((SIZE - 1) == L.size());
    CHECK(nums[5] == L.get(4));
  }

  SECTION("removeLast") {
    CHECK(nums[SIZE - 1] == L.removeLast());
    CHECK((SIZE - 1) == L.size());
    CHECK(nums[5] == L.get(5));
  }
}

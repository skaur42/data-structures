#define CATCH_CONFIG_MAIN
#include "BSTMap.h"
#include "BSTPrinter.h"
#include "catch.hpp"
#include <sstream>
#include <string>

using namespace std;

TEST_CASE("bstmap") {
  ds::BSTMap<int, string> bst; // a map from numbers to english words
  bst.put(5, "five");
  bst.put(2, "two");
  bst.put(1, "one");
  bst.put(4, "four");
  bst.put(6, "six");
  bst.put(7, "seven");
  bst.put(3, "three");
  // ds::BSTPrinter::print<int, string>(bst, cout);

  SECTION("get") {
    CHECK(bst.get(3) == "three");
    CHECK(bst.get(7) == "seven");
  }

  SECTION("remove") {
    bst.remove(5);
    // ds::BSTPrinter::print<int, string>(bst, cout);
    stringstream ss;
    ds::BSTPrinter::print<int, string>(bst, ss);
    CHECK(ss.str() == "                                              6:six                                             \n"
                      "                        ┌───────────────────────+───────────────────────┐                       \n"
                      "                      2:two                                          7:seven                    \n"
                      "            ┌───────────+───────────┐                                                           \n"
                      "          1:one                  4:four                                                         \n"
                      "                              ┌─────+                                                           \n"
                      "                           3:three                                                              \n");
  }
}

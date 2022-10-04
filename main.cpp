#define CATCH_CONFIG_MAIN
#include "DiGraphAdjList.h"
#include "catch.hpp"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TEST_CASE("directed graph") {
  ds::DiGraphAdjList g(5);
  g.addEdge(1, 2);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(3, 1);

  stringstream ss;
  ss << g;
  REQUIRE(ss.str() == "{0:[],1:[2,4],2:[3],3:[1],4:[],}");

  SECTION("hasEdge") {
    CHECK(g.hasEdge(2, 3) == true);
    CHECK(g.hasEdge(3, 2) == false);
  }

  SECTION("delEdge") {
    g.delEdge(1, 4);
    g.delEdge(3, 2); // delete an edge not in g should do nothing
    stringstream ss;
    ss << g;
    CHECK(ss.str() == "{0:[],1:[2],2:[3],3:[1],4:[],}");
  }

  SECTION("hasCycle") {
    CHECK(g.hasCycle() == true);
    g.delEdge(1, 2);
    CHECK(g.hasCycle() == false);
  }
}
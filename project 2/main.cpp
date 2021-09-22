#define CATCH_CONFIG_MAIN
#include "Calculator.h"
#include "catch.hpp"
#include <sstream>

TEST_CASE("Calculator") {
  std::string postfix = ds::Calculator::infixToPostfix(" 456   +  1123  ");
  REQUIRE(postfix == "456 1123 +");

  ds::BigInt sum = ds::Calculator::evaluatePostfix(postfix);
  std::stringstream ssum;
  ssum << sum;
  REQUIRE(ssum.str() == "1579");

  ds::BigInt r = ds::Calculator::evaluatePostfix(
      ds::Calculator::infixToPostfix(" 2 + ( 456 + 1123 ) - 23582190 "));
  std::stringstream ss;
  ss << r;
  REQUIRE(ss.str() == "23580609");
}

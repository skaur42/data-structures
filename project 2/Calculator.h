#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include "BigInt.h"
#include "VList.h"
#include <iostream>
#include <string>

namespace ds {

class Calculator {
public:
  static std::string infixToPostfix(const std::string &infix);
  static BigInt evaluatePostfix(const std::string &postfix);
  static BigInt calculate(const std::string &infix) {
    return evaluatePostfix(infixToPostfix(infix));
  }
};

} // namespace ds

#endif // __CALCULATOR_H__
#include "Calculator.h"
#include "BigInt.h"
#include <cctype>
#include <stack>

namespace ds {

/** Transform an `infix` expression to a `postifx` expression */
std::string Calculator::infixToPostfix(const std::string &infix) {
  // Empty character stack and blank postfix string.
  std::stack<char> opStack;
  std::string postFixString = "";
  char curOp; // current operator

  // Loop through the string
  for(int i = 0; i < infix.length(); i++){
    if(isspace(infix[i]) || infix[i] == '\n' || infix[i] == '\t'){
      continue;
    }
    if(isdigit(infix[i]) || isspace(infix[i])){
      // append it to the postfix string
      postFixString += infix[i];
    }else if (infix[i] == '-' || infix[i] == '+') {
      // add whitespace to the postfix string if it does not end with one
      if (postFixString.size() > 0 && !isspace(postFixString.back()))
        postFixString += ' ';
      curOp = infix[i]; // current operator
      while(!opStack.empty() && opStack.top() != '('){
        postFixString += opStack.top();
        // append the top operator from stack to the postfix string
        opStack.pop();
        if (postFixString.size() > 0 && !isspace(postFixString.back()))
          postFixString += ' ';
      }
      // push current operator to the opStack
      opStack.push(curOp);
      opStack.push(' ');

    }else if (infix[i] == '('){
      // push open parenthesis to the opStack
      opStack.push('(');
    }else if (infix[i] == ')'){
      // start popping off operators
      // until we run into '(' parenthesis
      while(!opStack.empty()){
        if(opStack.top() == '('){
          opStack.pop();
          break;
        }else{
          // append top operator in opStack to postfix string
          // pop top element from opStack
          postFixString += opStack.top(); 
          opStack.pop();
          if (postFixString.size() > 0 && !isspace(postFixString.back()))
            postFixString += ' ';
        }
      }
    }
  }
    // if there are remaining operators on opStack
    // pop them off and append them onto postfix string
    while(!opStack.empty()){
      postFixString += opStack.top();
      opStack.pop();
    }

 return postFixString;
}

/** Evaluate and return the value of `postfix` expression */
BigInt Calculator::evaluatePostfix(const std::string &postfix) {
  std::stack<BigInt> stk;
  std::string temp;
  // iterate through postfix string
  for(int i = 0; i < postfix.length(); i++){
    // if current char is a whitespace, skip
    if(isspace(postfix[i]) || postfix[i] == '\n'){
      continue;
    }
    // if postfix[i] is a digit then add to temp
    std::string temp;
    while(isdigit(postfix[i])){
      temp += postfix[i];
      i++;
    }  
    BigInt b(temp);
    stk.push(b);
    BigInt op1;
    BigInt op2;
    // if postfix[i] is '+' then add the top two BigInts from stk
    // pop them off and push the sum to stk
    if(postfix[i] == '+'){
      stk.pop();
      op1 = stk.top();
      stk.pop();
      op2 = stk.top();
      stk.pop();
      BigInt sum = op1+op2;
      stk.push((sum));
    }else if(postfix[i] == '-'){
      // if postfix[i] is '-' then subtract the top two BigInts from stk
      // pop them off and push the difference to stk
      stk.pop();
      op1 = stk.top();
      stk.pop();
      op2 = stk.top();
      stk.pop();
      stk.push(op1 - op2);
    }
  }

  return stk.top();
}

} // namespace ds

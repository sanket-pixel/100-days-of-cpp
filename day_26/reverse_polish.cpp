#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>
class Stack {
  std::vector<int> elements_{};

public:
  void push(int val) { elements_.push_back(val); }
  void pop() { elements_.pop_back(); }
  int top() { return elements_.back(); }
  std::size_t size() { return elements_.size(); }
};

class Solution {
public:
  int evalRPN(std::vector<std::string> &tokens) {
    Stack *operands = new Stack();
    for (const std::string &c : tokens) {
      if (c == "+") {
        int op2 = operands->top();
        operands->pop();
        int op1 = operands->top();
        operands->pop();
        operands->push(op1 + op2);
      } else if (c == "-") {
        int op2 = operands->top();
        operands->pop();
        int op1 = operands->top();
        operands->pop();
        operands->push(op1 - op2);
      } else if (c == "*") {
        int op2 = operands->top();
        operands->pop();
        int op1 = operands->top();
        operands->pop();
        operands->push(op1 * op2);
      } else if (c == "/") {
        int op2 = operands->top();
        operands->pop();
        int op1 = operands->top();
        operands->pop();
        operands->push(op1 / op2);
      } else {
        int value = std::stoi(c);
        operands->push(value);
      }
    }
    return operands->top();
  }
};
int main() {
  std::vector<std::string> tokens{"4", "13", "5", "/", "+"};
  Solution sol;
  int answer = sol.evalRPN(tokens);
  std::cout << answer << std::endl;
}
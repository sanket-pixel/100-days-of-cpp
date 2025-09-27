#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
class Stack {
  std::vector<char> elements_;

public:
  void push(char character) { elements_.push_back(character); }
  void pop() { elements_.pop_back(); }
  char top() { return elements_.back(); }
  std::size_t size() { return elements_.size(); }
};

class Solution {
public:
  bool isValid(std::string s) {
    std::unordered_map<char, char> matches{{'[', ']'}, {'{', '}'}, {'(', ')'}};
    Stack *open_stack = new Stack();
    for (int i = 0; i < s.size(); i++) {
      char p = s.at(i);
      if (p == '[' || p == '(' || p == '{') {
        open_stack->push(p);
      } else if (p == ']' || p == ')' || p == '}') {
        if (open_stack->size() == 0) {
          return false;
        }
        char top = open_stack->top();
        if (p == matches[top]) {
          open_stack->pop();
        } else {
          return false;
        }
      } else {
        return false;
      }
    }
    if (open_stack->size() == 0) {
      return true;
    } else {
      return false;
    }
  }
};
int main() {
  std::string valid_parentheses = "[{()}]";
  std::string invalid_parentheses = "]";
  Solution sol;
  if (sol.isValid(invalid_parentheses)) {
    std::cout << invalid_parentheses << " is valid";
  } else {
    std::cout << invalid_parentheses << " is invalid";
  }
}
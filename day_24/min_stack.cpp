#include <iostream>
#include <vector>

class MinStack {
public:
  std::vector<int> elements_;
  std::vector<int> minimum_;
  void push(int val) {
    elements_.push_back(val);
    if (minimum_.empty()) {
      minimum_.push_back(val);
      return;
    }
    int minimum = minimum_.back();
    if (val < minimum_.back()) {
      minimum = val;
    }
    minimum_.push_back(minimum);
  }

  void pop() {
    if (!elements_.empty()) {
      elements_.pop_back();
      minimum_.pop_back();
    }
  }

  int top() {
    if (!elements_.empty()) {
      return elements_.back();
    }
  }

  int GetMin() {
    if (!elements_.empty()) {
      return minimum_.back();
    }
  }
};

int main() {
  MinStack *min_stack = new MinStack();
  min_stack->push(3);
  min_stack->push(4);
  min_stack->push(5);
  min_stack->push(2);
  min_stack->push(4);
  std::cout << min_stack->GetMin() << std::endl;
  min_stack->pop();
  std::cout << min_stack->GetMin() << std::endl;
  min_stack->pop();
  std::cout << min_stack->GetMin() << std::endl;
  min_stack->pop();
  std::cout << min_stack->GetMin() << std::endl;
}
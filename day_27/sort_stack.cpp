#include <iostream>
#include <vector>

class Stack {
  std::vector<int> elements_;

public:
  void push(int val) { elements_.push_back(val); }
  void pop() { elements_.pop_back(); }
  int top() { return elements_.back(); }
  std::size_t size() { return elements_.size(); }
  void print() {
    for (int i = 0; i < elements_.size(); i++) {
      std::cout << elements_.at(i) << " ";
    }
    std::cout << std::endl;
  }
};

class Solution {
public:
  Stack *SortStack(Stack *nums) {
    Stack *temp = new Stack();
    while (nums->size() > 0) {
      int popped_element = nums->top();
      nums->pop();
      while (temp->size() > 0 && temp->top() > popped_element) {
        int temp_popped = temp->top();
        temp->pop();
        nums->push(temp_popped);
      }
      temp->push(popped_element);
    }
    return temp;
  }
};

int main() {
  Stack *nums = new Stack();
  nums->push(1);
  nums->push(2);
  nums->push(3);
  nums->push(5);
  nums->push(4);
  nums->print();

  Solution sol;
  Stack *sorted_stack = sol.SortStack(nums);
  sorted_stack->print();
}
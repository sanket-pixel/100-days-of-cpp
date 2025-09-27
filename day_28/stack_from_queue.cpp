#include <iostream>
#include <queue>
class MyStack {
public:
  std::queue<int> q1_;
  MyStack() { q1_ = std::queue<int>{}; }
  void push(int x) {
    q1_.push(x);
    for (int i = 0; i < q1_.size() - 1; i++) {
      int top = q1_.front();
      q1_.pop();
      q1_.push(top);
    }
  }
  int top() { return q1_.front(); }
  int pop() {
    int top = q1_.front();
    q1_.pop();
    return top;
  }
  bool empty() { return q1_.empty(); }
};

int main() {
  MyStack *stack = new MyStack();
  stack->push(1);
  stack->push(2);
  stack->push(3);
  std::cout << stack->top() << std::endl;
  stack->pop();
  std::cout << stack->top() << std::endl;
}
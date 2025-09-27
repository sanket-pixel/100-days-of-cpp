#include <iostream>
#include <queue>
#include <stack>

class Solution {
public:
  std::queue<int> ReverseQueueUsingStack(std::queue<int> q, int k) {
    std::queue<int> rev_q;
    std::stack<int> temp_stack;
    int q_size = q.size();
    for (int i = 0; i < k; i++) {
      int c = q.front();
      q.pop();
      temp_stack.push(c);
    }
    for (int i = 0; i < q_size; i++) {
      if (i < k) {
        int top = temp_stack.top();
        temp_stack.pop();
        rev_q.push(top);
      } else {
        int front = q.front();
        q.pop();
        rev_q.push(front);
      }
    }
    return rev_q;
  }
};
int main() {
  std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int k = 6;
  std::queue<int> q;
  for (auto n : nums) {
    q.push(n);
  }
  Solution sol;
  std::queue<int> rev_q = sol.ReverseQueueUsingStack(q, k);
  std::queue<int> temp = rev_q;
  while (!temp.empty()) {
    std::cout << temp.front() << " ";
    temp.pop();
  }
  std::cout << std::endl;
}

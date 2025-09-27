#include <iostream>
#include <queue>

class Solution {
public:
  int timeRequiredToBuy(std::vector<int> tickets, int k) {
    int result = 0;
    for (int i = 0; i < tickets.size(); i++) {
      if (i <= k) {
        result += std::min(tickets[k], tickets[i]);
      } else {
        result += std::min(tickets[i], tickets[k] - 1);
      }
    }
    return result;
  }
};
int main() {
  std::vector<int> tickets{2, 3, 2};
  int k = 2;
  Solution sol;
  int time = sol.timeRequiredToBuy(tickets, k);
  std::cout << time << std::endl;
}
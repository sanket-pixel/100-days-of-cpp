#include <iostream>
#include <queue>
#include <unordered_set>
#include <variant>
#include <vector>

using namespace std;
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int max_profit = 0;
    int l = 0;
    int r = 1;
    while (r != prices.size()) {
      if (prices[l] < prices[r]) {
        int profit = prices[r] - prices[l];
        max_profit = max(max_profit, profit);
      } else {
        l = r;
      }
      r += 1;
    }
    return max_profit;
  }
};

int main() {
  Solution solution;
  vector<int> prices{7, 1, 5, 3, 6, 4};
  auto max_profit = solution.maxProfit(prices);
  cout << max_profit << endl;
  return 0;
}
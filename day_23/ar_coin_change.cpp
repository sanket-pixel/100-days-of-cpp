#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int num_minimum_coins(std::vector<int> coins, int amount) {
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (int c = 0; c < coins.size(); c++) {
        if (i - coins[c] >= 0) {
          dp[i] = std::min(dp[i], dp[i - coins[c]] + 1);
        }
      }
    }
    if (dp[amount] == amount + 1) {
      return -1;
    } else {
      return dp[amount];
    }
  }
};
int main() {
  std::vector<int> coins{5, 2, 3, 1};
  int amount = 7;
  Solution sol;
  int num_min_coins = sol.num_minimum_coins(coins, amount);
  std::cout << num_min_coins << std::endl;
}
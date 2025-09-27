#include <iostream>
#include <unordered_map>
#include <vector>
class Solution {
public:
  int coinChange(std::vector<int> coins, int target) {
    std::vector<int> dp(target + 1, target + 1);
    dp[0] = 0;
    for (int i = 1; i <= target; i++) {
      for (int c : coins) {
        if (i - c >= 0) {
          dp[i] = std::min(dp[i - c] + 1, dp[i]);
        }
      }
    }
    if (dp[target] == target + 1) {
      return -1;
    } else {
      return dp[target];
    }
  }
};
int main() {
  std::vector<int> coins{1, 3, 4, 5};
  int target = 7;
  Solution sol;
  int min_coins = sol.coinChange(coins, target);
  std::cout << min_coins << std::endl;
}
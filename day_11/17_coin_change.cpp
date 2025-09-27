#include <algorithm>
#include <deque>
#include <iostream>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    std::vector<int> min_coins_all(amount + 1, amount + 1);
    min_coins_all[0] = 0;
    for (int i = 1; i < amount + 1; i++) {
      for (int c = 0; c < coins.size(); c++) {
        if (i - coins[c] >= 0) {
          min_coins_all[i] =
              min(min_coins_all[i], 1 + min_coins_all[i - coins[c]]);
        }
      }
    }
    if (min_coins_all[amount] == amount + 1) {
      return -1;
    } else {
      return min_coins_all[amount];
    }
  }
};
int main() {
  Solution sol;
  vector<int> coins = {2, 2, 2};
  int amount = 3;
  int minimum_coins = sol.coinChange(coins, amount);
  std::cout << "Minimum coins needed are " << minimum_coins;
}

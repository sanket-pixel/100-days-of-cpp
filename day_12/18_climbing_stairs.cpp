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
  int climbStairs(int n) {
    std::vector<int> dp(n + 1, 0);
    std::vector<int> valid_steps{1, 2};
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (const auto &s : valid_steps) {
        dp[i] = dp[i] + dp[i - s];
      }
    }
    return dp[n];
  }
};
int main() {
  Solution sol;
  int n = 2;
  int distinct_steps = sol.climbStairs(n);
  std::cout << "Distinct steps to climb " << n << " stairs " << distinct_steps;
}

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
  vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    int offset = 1;
    for (int i = 1; i <= n; i++) {
      if (offset * 2 == i) {
        offset = i;
      }
      dp[i] = 1 + dp[i - offset];
    }
    return dp;
  }
};
int main() {
  Solution sol;
  int n = 0;
  vector<int> bit_count = sol.countBits(n);
  for (int i = 0; i <= n; i++) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  for (int i = 0; i <= n; i++) {
    std::cout << bit_count[i] << " ";
  }
  std::cout << std::endl;
}

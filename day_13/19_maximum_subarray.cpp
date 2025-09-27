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
  int maxSubArray(vector<int> nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      dp[i] = max(nums[i], nums[i] + dp[i - 1]);
    }
    int max_sum = std::max_element(dp.begin(), dp.end())[0];
    return max_sum;
  }

  int maxSubArray2(vector<int> &nums) {
    int currentSum = nums[0];
    int maxSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      currentSum = max(nums[i], currentSum + nums[i]);
      maxSum = max(maxSum, currentSum);
    }
    return maxSum;
  }
};
int main() {
  Solution sol;
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int max_sum = sol.maxSubArray(nums);
  std::cout << "Max sum is " << max_sum;
}

#include <iostream>
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    int current_sum = nums[0];
    int max_sum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      current_sum = std::max(nums[i], current_sum + nums[i]);
      max_sum = std::max(current_sum, max_sum);
    }
    return max_sum;
  }
};
int main() {
  std::vector<int> a{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  Solution sol;
  int max_sum = sol.maxSubArray(a);
  std::cout << max_sum << std::endl;
}
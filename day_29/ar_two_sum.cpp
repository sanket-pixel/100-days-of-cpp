#include <iostream>
#include <unordered_map>
#include <vector>
class Solution {
public:
  std::vector<int> twoSum(std::vector<int> nums, int target) {
    std::unordered_map<int, int> h{};
    for (int i = 0; i < nums.size(); i++) {
      int diff = target - nums[i];
      if (h.find(diff) != h.end()) {
        return {h[diff], i};
      }
      h[nums[i]] = i;
    }
  }
};
int main() {
  std::vector<int> nums{5, 3, 9, 1, 2, 3, 4};
  int target = 13;
  Solution sol;
  std::vector<int> missing = sol.twoSum(nums, target);
  for (const auto &m : missing) {
    std::cout << m << " ";
  }
  std::cout << std::endl;
}
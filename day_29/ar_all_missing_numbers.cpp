#include <iostream>
#include <vector>
class Solution {
public:
  std::vector<int> findDisappearedNumbers(std::vector<int> nums) {
    std::vector<int> missing{};
    for (int i = 0; i < nums.size(); i++) {
      while (nums[i] != nums[nums[i] - 1]) {
        int temp = nums[nums[i] - 1];
        nums[nums[i] - 1] = nums[i];
        nums[i] = temp;
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        missing.push_back(i + 1);
      }
    }
    return missing;
  }

  std::vector<int> findDisappearedNumbers2(std::vector<int> nums) {
    std::vector<int> missing{};
    for (auto c : nums) {
      while (c != nums[c - 1]) {
        std::swap(c, nums[c - 1]);
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        missing.push_back(i + 1);
      }
    }
    return missing;
  }
};
int main() {
  std::vector<int> nums{3, 1, 5, 1, 6, 3};
  Solution sol;
  std::vector<int> missing = sol.findDisappearedNumbers2(nums);
  for (const auto &m : missing) {
    std::cout << m << " ";
  }
  std::cout << std::endl;
}
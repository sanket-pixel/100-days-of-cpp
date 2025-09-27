#include <iostream>
#include <unordered_map>
#include <vector>
class Solution {
public:
  int longestMountain(std::vector<int> nums) {
    int longest = 0;
    for (int i = 1; i < nums.size() - 1; i++) {
      if (nums.at(i - 1) < nums.at(i) && nums.at(i + 1) < nums.at(i)) {
        int L = i - 1;
        int R = i + 1;
        while (L > 0 && nums[L - 1] < nums[L]) {
          L--;
        }
        while (R < nums.size() - 1 && nums[R + 1] < nums.at(R)) {
          R++;
        }
        longest = std::max(longest, R - L + 1);
      }
    }
    return longest;
  }
};
int main() {
  std::vector<int> nums{1, 2, 3, 4, 5, 6, 7};
  Solution sol;
  int longest = sol.longestMountain(nums);
  std::cout << longest << std::endl;
}
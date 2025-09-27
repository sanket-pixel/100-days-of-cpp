#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(std::vector<int> nums) {
    vector<int> sorted_nums = nums;
    vector<vector<int>> triplets;
    std::sort(sorted_nums.begin(), sorted_nums.end());
    for (int i = 0; i < sorted_nums.size(); i++) {
      if (nums[i] > 0) {
        break;
      }
      if (i > 0 && sorted_nums.at(i - 1) == sorted_nums.at(i)) {
        continue;
      }
      int curr = sorted_nums.at(i);
      int L = i + 1;
      int R = sorted_nums.size() - 1;
      while (L < R) {
        int sum = curr + sorted_nums.at(L) + sorted_nums.at(R);
        if (sum < 0) {
          L++;
        } else if (sum > 0) {
          R--;
        } else {
          triplets.push_back(
              {sorted_nums.at(i), sorted_nums.at(L), sorted_nums.at(R)});
          L++;
          R--;
          while (L < R && sorted_nums[L - 1] == sorted_nums[L]) {
            L++;
          }
        }
      }
    }
    return triplets;
  }
};
int main() {
  vector<int> nums{-1, 0, 1, 2, -1, -4};
  Solution sol;
  vector<vector<int>> triplets = sol.threeSum(nums);
  for (auto &t : triplets) {
    std::cout << t.at(0) << " " << t.at(1) << " " << t.at(2);
  }
  std::cout << std::endl;
}
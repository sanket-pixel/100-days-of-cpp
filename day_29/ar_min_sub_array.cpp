#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int minSubArray2(vector<int> nums, int target) {
    int L = 0;
    int R = 0;
    int curr = nums.at(L);
    int min_len = INT32_MAX;
    bool found = false;
    while (L <= R && R < nums.size()) {
      if (curr >= target) {
        found = true;
        min_len = std::min(min_len, R - L + 1);
        curr = curr - nums.at(L);
        L++;
      } else if (curr < target) {
        R++;
        if (R < nums.size()) {
          curr = curr + nums.at(R);
        }
      }
    }
    if (found) {
      return min_len;
    } else {
      return 0;
    }
  }
  int minSubArray(vector<int> nums, int target) {
    int l = 0;
    int total = 0;
    int min_len = INT32_MAX;
    bool found = false;
    for (int r = 0; r < nums.size(); r++) {
      total = total + nums.at(r);
      while (total >= target) {
        found = true;
        min_len = std::min(min_len, r - l + 1);
        total = total - nums.at(l);
        l++;
      }
    }
    if (found) {
      return min_len;
    } else {
      return 0;
    }
  }
};
int main() {
  vector<int> nums{2, 3, 1, 2, 4, 3};
  int target = 7;
  Solution sol;
  int min_subarray_len = sol.minSubArray(nums, target);
  std::cout << min_subarray_len << std::endl;
}
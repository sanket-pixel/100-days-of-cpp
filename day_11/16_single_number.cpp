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
  int singleNumber(int target, vector<int> &nums) {
    int l = 0;
    int min_sub_length = INT_MAX;
    int total = 0;
    for (int r = 0; r < nums.size(); r++) {
      total += nums[r];
      while (total >= target) {
        min_sub_length = min(min_sub_length, r - l + 1);
        total = total - nums[l];
        l++;
      }
    }
    if (min_sub_length == INT_MAX) {
      return 0;
    } else {
      return min_sub_length;
    }
  }
};
int main() {
  Solution sol;
  vector<int> input = {1, 2, 3, 4, 5};
  int target = 15;
  int minimum_subarray_length = sol.singleNumber(target, input);
  std::cout << "Minimum sub array length is " << minimum_subarray_length;
}

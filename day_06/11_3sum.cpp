#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> triplets;
    vector<int> sorted_nums = nums;
    std::sort(sorted_nums.begin(), sorted_nums.end());
    for (int i = 0; i < sorted_nums.size(); i++) {
      int current_value = sorted_nums[i];
      if (i > 0 && sorted_nums[i] == sorted_nums[i - 1]) {
        continue;
      }
      int left = i + 1;
      int right = sorted_nums.size() - 1;
      while (left < right) {
        int current_sum =
            sorted_nums.at(i) + sorted_nums.at(left) + sorted_nums.at(right);
        if (current_sum < 0) {
          left++;
        } else if (current_sum > 0) {
          right--;
        } else {
          triplets.push_back(
              {current_value, sorted_nums.at(left), sorted_nums.at(right)});
          left++;
          while (left < right && sorted_nums[left] == sorted_nums[left - 1]) {
            left++;
          }
        }
      }
    }
    return triplets;
  }
};

int main() {
  Solution sol;
  vector<int> input = {0, 0, 0, 0};
  auto tripets = sol.threeSum(input);
  for (auto t : tripets) {
    cout << t.at(0) << " " << t.at(1) << " " << t.at(2) << endl;
  }
  return 0;
}
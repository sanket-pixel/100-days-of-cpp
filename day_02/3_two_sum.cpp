#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> twoSum_slow(vector<int> &nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (nums[i] + nums[j] == target) {
          return {i, j};
        }
      }
    }
    return {};
  }

  vector<int> twoSum_fast(vector<int> &nums, int target) {
    int n = nums.size();
    unordered_map<int, int> indices_map;
    for (int i = 0; i < n; i++) {
      int difference = target - nums[i];
      if (indices_map.find(difference) == indices_map.end()) {
        indices_map[nums[i]] = i;
      } else {
        return {i, indices_map[difference]};
      }
    }
    return {};
  }

  vector<int> small_count(vector<int> &nums) {
    vector<int> sorted_nums = nums;
    std::sort(sorted_nums.begin(), sorted_nums.end());
    unordered_map<int, int> indices_map;
    for (int i = 0; i < sorted_nums.size(); i++) {
      if (indices_map.find(sorted_nums[i]) == indices_map.end()) {
        indices_map[sorted_nums[i]] = i;
      }
    }
    vector<int> smallest_vec(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
      smallest_vec[i] = indices_map[nums[i]];
    }
    return smallest_vec;
  }
};

int main() {
  Solution solution;
  std::vector<int> vec{2, 11, 7, 15};
  int target = 26;
  auto two_sum_indices = solution.twoSum_fast(vec, target);
  std::cout << "Two sum indices : ";
  for (int idx : two_sum_indices) {
    std::cout << idx << ", ";
  }

  std::vector<int> vec2{8, 1, 2, 2, 3};
  auto vec_small = solution.small_count(vec2);
  for (const auto elem : vec_small) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}

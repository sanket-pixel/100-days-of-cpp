#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> smallerNumbersThanCurrent_slow(vector<int> &nums) {
    int n = nums.size();
    vector<int> small_count{};
    for (int i = 0; i < n; i++) {
      int count = 0;
      for (int j = 0; j < n; j++) {
        if (i != j) {
          if (nums[j] < nums[i]) {
            count++;
          }
        }
      }
      small_count.push_back(count);
    }
    return small_count;
  }

  vector<int> smallerNumbersThanCurrent_fast(vector<int> &nums) {
    vector<int> sorted_nums = nums;
    vector<int> smallest_count;
    std::sort(sorted_nums.begin(), sorted_nums.end());
    unordered_map<int, int> indices_map{};
    for (int i = 0; i < sorted_nums.size(); i++) {
      if (indices_map.find(sorted_nums[i]) == indices_map.end()) {
        indices_map[sorted_nums[i]] = i;
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      smallest_count.push_back(indices_map[nums[i]]);
    }
    return smallest_count;
  }
};

int main() {
  Solution solution;
  std::vector<int> vec{8, 1, 2, 2, 3};
  auto smallest_count = solution.smallerNumbersThanCurrent_fast(vec);
  std::cout << "All missing numbers : ";
  for (int number : smallest_count) {
    std::cout << number << ", ";
  }
}
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
  vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    std::vector<int> sorted_arr = arr;
    std::sort(sorted_arr.begin(), sorted_arr.end());
    int minimum_absolute_difference = INT_MAX;
    vector<vector<int>> minimum_distance_pair = {};
    for (int i = 0; i < sorted_arr.size() - 1; i++) {
      int current_absolute_difference = abs(sorted_arr[i + 1] - sorted_arr[i]);
      if (current_absolute_difference < minimum_absolute_difference) {
        minimum_distance_pair.clear();
        minimum_absolute_difference = current_absolute_difference;
        minimum_distance_pair.push_back({sorted_arr[i], sorted_arr[i + 1]});
      } else if (current_absolute_difference == minimum_absolute_difference) {
        minimum_distance_pair.push_back({sorted_arr[i], sorted_arr[i + 1]});
      }
    }
    return minimum_distance_pair;
  }
};
int main() {
  Solution sol;
  vector<int> input = {3, 8, -10, 23, 19, -4, -14, 27};
  vector<vector<int>> minimum_difference_pair = sol.minimumAbsDifference(input);
  for (const auto &p : minimum_difference_pair) {
    std::cout << "{ " << p[0] << ", " << p[1] << "} " << std::endl;
  }
}

#include <algorithm>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &arr, int k) {
    std::unordered_set<int> unique_nums;
    for (int i = 0; i < arr.size(); i++) {
      if (unique_nums.find(arr[i]) == unique_nums.end()) {
        unique_nums.insert(arr[i]);
      } else {
        return true;
      }
      if (unique_nums.size() > k) {
        unique_nums.erase(arr[i - k]);
      }
    }
    return false;
  }

  bool containsNearbyDuplicate_fast(vector<int> &arr, int k) {
    std::unordered_map<int, int> seen;
    for (int i = 0; i < arr.size(); i++) {
      int value = arr[i];
      if (seen.find(value) != seen.end() && i - seen[arr[i]] <= k) {
        return true;
      } else {
        seen[arr[i]] = i;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  vector<int> input = {0, 2, 3, 1, 2, 5, 8};
  int k = 2;
  bool contains_duplicate_nearby = sol.containsNearbyDuplicate_fast(input, k);
  if (contains_duplicate_nearby) {
    std::cout << "Contains duplicate nearby" << std::endl;
  } else {
    std::cout << "Does not contain duplicate nearby" << std::endl;
  }
  return 0;
}
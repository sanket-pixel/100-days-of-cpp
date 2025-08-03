#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    std::map<int, int> unique_counts;
    for (int num : nums) {
      unique_counts[num]++;
      if (unique_counts[num] >= 2) {
        return true;
      }
    }
    return false;
  }

  bool containsDuplicate2(vector<int> &nums) {
    unordered_set<int> seen;
    for (const auto num : nums) {
      if (seen.count(num))
        return true;
      seen.insert(num);
    }
    return false;
  }
};

int main() {
  Solution solution;
  std::vector<int> vec{1, 2, 2, 3, 4};
  std::cout << solution.containsDuplicate2(vec) << std::endl;
}
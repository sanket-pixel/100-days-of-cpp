#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  std::vector<int> allmissingNumber_slow(vector<int> &nums) {
    // this has memory complexity of O(N)
    int n = nums.size();
    std::vector<int> missing_numbers{};
    std::unordered_set<int> unique_numbers{nums.begin(), nums.end()};
    for (int i = 1; i < n; i++) {
      if (unique_numbers.count(i) == 0)
        missing_numbers.push_back(i);
    }
    return missing_numbers;
  }

  std::vector<int> allmissingNumber_fast(vector<int> &nums) {
    // constant time memory O(1)
    // using cyclical sorting
    // the idea is to first get all the element at their correct ideal indices
    // here the expected value at index i is (i+1) since numbers go from (1,n)
    // this is achieved by swapping numbers with the number at their ideal index
    // Example, swap 4 with the number at its correct index ( which is 4-1=3)
    int n = nums.size();
    std::vector<int> all_missing_numbers{};
    for (int i = 0; i < n; i++) {
      if (nums[i] != i + 1) {
        // remember this by heart
        while (nums[nums[i] - 1] != nums[i]) {
          swap(nums[nums[i] - 1], nums[i]);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] != i + 1) {
        all_missing_numbers.push_back(i + 1);
      }
    }
    return all_missing_numbers;
  }
};

int main() {
  Solution solution;
  std::vector<int> vec{4, 3, 2, 7, 8, 2, 3, 1};
  auto all_missing_numbers = solution.allmissingNumber_fast(vec);
  std::cout << "All missing numbers : ";
  for (int number : all_missing_numbers) {
    std::cout << number << ", ";
  }
}
#include <iostream>
#include <map>
#include <vector>

using namespace std;
class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int n = nums.size();
    int expected_sum = n * (n + 1) / 2;
    int current_sum = 0;
    for (int i = 0; i < n; i++) {
      current_sum += nums[i];
    }
    int missing_number = expected_sum - current_sum;
    return missing_number;
  }
};

int main() {
  Solution solution;
  std::vector<int> vec{0, 3, 1};
  std::cout << "The missing number is " << solution.missingNumber(vec)
            << std::endl;
}
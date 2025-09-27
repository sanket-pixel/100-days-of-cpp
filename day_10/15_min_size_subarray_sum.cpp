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
  int singleNumber(vector<int> &nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
      result = result ^ nums[i];
    }
    return result;
  }
};
int main() {
  Solution sol;
  vector<int> input = {4, 1, 2, 1, 2};
  int single_number = sol.singleNumber(input);
  std::cout << "Single number is " << single_number;
}

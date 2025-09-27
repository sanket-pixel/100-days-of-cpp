#include <algorithm>
#include <deque>
#include <iostream>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class NumArray {
public:
  NumArray(vector<int> &nums) {
    dp_.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
      dp_.push_back(dp_.back() + nums[i]);
    }
  }

  int sumRange(int left, int right) {
    if (left == 0) {
      return dp_[right];

    } else {
      return dp_[right] - dp_[left - 1];
    }
  }
  vector<int> dp_;
};

int main() {
  std::vector<int> array = {1, 2, 3, 4, 5, 6};
  NumArray obj = NumArray(array);
  std::cout << obj.sumRange(0, 2);
}

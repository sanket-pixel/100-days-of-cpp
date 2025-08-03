#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    // get the index of the first positive element
    int first_positive_index = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= 0) {
        first_positive_index = i;
        break;
      }
    }
    if (first_positive_index == -1) {
      first_positive_index = nums.size();
    }

    // slice the negative numbers and reverse
    auto negative_nums =
        vector<int>(nums.begin(), nums.begin() + first_positive_index);
    reverse(negative_nums.begin(), negative_nums.end());
    // slice the positive values
    auto postiive_nums =
        vector<int>(nums.begin() + first_positive_index, nums.end());

    int negative_pointer = 0;
    int positive_pointer = 0;
    vector<int> sorted_squares(nums.size(), 0);
    int index_counter = 0;
    while (negative_pointer < negative_nums.size() &&
           positive_pointer < postiive_nums.size()) {
      int negative_num_square =
          negative_nums[negative_pointer] * negative_nums[negative_pointer];
      int positive_num_square =
          postiive_nums[positive_pointer] * postiive_nums[positive_pointer];
      if (negative_num_square < positive_num_square) {
        sorted_squares[index_counter] = negative_num_square;
        negative_pointer++;
      } else {
        sorted_squares[index_counter] = positive_num_square;
        positive_pointer++;
      }
      index_counter++;
    }
    while (positive_pointer < postiive_nums.size()) {
      sorted_squares[index_counter] =
          postiive_nums[positive_pointer] * postiive_nums[positive_pointer];
      positive_pointer++;
      index_counter++;
    }
    while (negative_pointer < negative_nums.size()) {
      sorted_squares[index_counter] =
          negative_nums[negative_pointer] * negative_nums[negative_pointer];
      negative_pointer++;
      index_counter++;
    }
    return sorted_squares;
  }

  vector<int> sortedSquares2(vector<int> &nums) {
    vector<int> sorted_squares{};
    int left_pointer = 0;
    int right_pointer = nums.size() - 1;
    while (left_pointer <= right_pointer) {
      if (abs(nums[left_pointer]) < abs(nums[right_pointer])) {
        sorted_squares.push_back(nums[right_pointer] * nums[right_pointer]);
        right_pointer--;
      } else {
        sorted_squares.push_back(nums[left_pointer] * nums[left_pointer]);
        left_pointer++;
      }
    }
    reverse(sorted_squares.begin(), sorted_squares.end());
    return sorted_squares;
  }
};

int main() {
  Solution sol;
  vector<int> input = {-4, -1, 0, 3, 10};
  auto sorted_sqaures = sol.sortedSquares2(input);
  for (auto num : sorted_sqaures) {
    cout << num << " " << endl;
  }
  return 0;
}
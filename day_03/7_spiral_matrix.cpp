#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> spiral_matrix;
    int top = 0;
    int right = matrix[0].size() - 1;
    int bottom = matrix.size() - 1;
    int left = 0;
    while (top <= bottom and left <= right) {
      // Step 1 : Get first row and top++
      for (int i = left; i <= right; i++) {
        spiral_matrix.push_back(matrix.at(top).at(i));
      }
      top++;
      // Step 2 : Get last element of each row and right--
      for (int i = top; i <= bottom; i++) {
        spiral_matrix.push_back(matrix.at(i).at(right));
      }
      right--;
      if (top <= bottom) {
        // Step 3 : Get last row reversed and bottom--
        for (int i = right; i >= left; i--) {
          spiral_matrix.push_back(matrix.at(bottom).at(i));
        }
        bottom--;
      }

      if (left <= right) {
        // Step 4 : Get first element of each row and left++
        for (int i = bottom; i >= top; i--) {
          spiral_matrix.push_back(matrix.at(i).at(left));
        }
        left++;
      }
    }
    return spiral_matrix;
  }
};
int main() {
  Solution solution;
  std::vector<vector<int>> vec{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  auto spiral_matrix = solution.spiralOrder(vec);
  for (auto element : spiral_matrix) {
    std::cout << element << " ";
  }
}
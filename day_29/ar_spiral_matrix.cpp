#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> spiral_order;
    int top = 0;
    int left = 0;
    int bottom = matrix.size() - 1;
    int right = matrix.at(0).size() - 1;
    // get first row
    while (top <= bottom && left <= right) {
      for (int i = left; i <= right; i++) {
        spiral_order.push_back(matrix.at(top).at(i));
      }
      top++;
      // get last column
      for (int i = top; i <= bottom; i++) {
        spiral_order.push_back(matrix.at(i).at(right));
      }
      right--;
      // get last row in reverse
      if (top <= bottom) {
        for (int i = right; i >= left; i--) {
          spiral_order.push_back(matrix.at(bottom).at(i));
        }
      }
      bottom--;
      if (left <= right) {
        for (int i = bottom; i >= top; i--) {
          spiral_order.push_back(matrix.at(i).at(left));
        }
      }
      left++;
    }
    return spiral_order;
  }
};

int main() {
  int data[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  vector<vector<int>> matrix;
  for (int r = 0; r < 3; r++) {
    vector<int> row;
    for (int c = 0; c < 4; c++) {
      row.push_back(data[r][c]);
    }
    matrix.push_back(row);
  }
  Solution sol;
  auto spiral = sol.spiralOrder(matrix);
}
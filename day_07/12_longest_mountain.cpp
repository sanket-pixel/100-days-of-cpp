#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int longestMountain(vector<int> &arr) {
    int longest_mountain_size = 0;
    for (int i = 1; i < arr.size() - 1; i++) {
      if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
        int L = i - 1;
        int R = i + 1;
        while (L > 0 && arr[L - 1] < arr[L]) {
          L--;
        }
        while (R < arr.size() - 1 && arr[R + 1] < arr[R]) {
          R++;
        }
        longest_mountain_size = max(longest_mountain_size, R - L + 1);
      }
    }
    return longest_mountain_size;
  }
};

int main() {
  Solution sol;
  vector<int> input = {0, 1, 4, 7, 3, 2, 5};
  auto mountain_length = sol.longestMountain(input);
  std::cout << "Longest mountain size is " << mountain_length << std::endl;
  return 0;
}
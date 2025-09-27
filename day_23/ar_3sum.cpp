#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> three_sum(std::vector<int> &a) {
    std::sort(a.begin(), a.end());
    std::vector<std::vector<int>> triplets = {};
    for (int i = 0; i < a.size(); i++) {
      if (i > 0 && a[i] == a[i - 1]) {
        continue;
      }
      int L = i + 1;
      int R = a.size() - 1;
      while (L < R) {
        int sum = a[i] + a[L] + a[R];
        if (sum < 0) {
          L++;
        } else if (sum > 0) {
          R--;
        } else {
          triplets.push_back({a[i], a[L], a[R]});
          L++;
          R--;
          while (L < R && a[L - 1] == a[L]) {
            L++;
          }
        }
      }
    }
    return triplets;
  }
};
int main() {
  std::vector<int> a{2,  -3, 0, -2, -5, -5, -4, 1,  2,
                     -2, 2,  0, 2,  -4, 5,  5,  -10};
  Solution sol;
  std::vector<std::vector<int>> three_sum = sol.three_sum(a);
  for (const auto &triplet : three_sum) {
    std::cout << triplet.at(0) << " " << triplet.at(1) << " " << triplet.at(2)
              << std::endl;
  }
}
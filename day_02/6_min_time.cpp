#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {
    int total_time = 0;
    for (int i = 0; i < points.size() - 1; i++) {
      vector<int> current_point = points[i];
      vector<int> next_point = points[i + 1];
      total_time += max(abs(next_point[0] - current_point[0]),
                        abs(next_point[1] - current_point[1]));
    }
    return total_time;
  }
};

int main() {
  Solution solution;
  std::vector<vector<int>> vec{{1, 1}, {3, 4}, {-1, 0}};
  auto minimum_time = solution.minTimeToVisitAllPoints(vec);
  std::cout << "Minimum time needed " << minimum_time << std::endl;
}
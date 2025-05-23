#include <iostream>
#include <queue>
#include <unordered_set>
#include <variant>
#include <vector>

using namespace std;
class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c] == '1' && !visited[r][c]) {
          bfs(grid, r, c, visited);
          count++;
        }
      }
    }
    return count;
  }

  vector<pair<int, int>> directions_{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  void bfs(vector<vector<char>> &grid, int r, int c,
           vector<vector<bool>> &visited) {
    queue<pair<int, int>> search_list;
    int rows = grid.size();
    int cols = grid[0].size();
    visited[r][c] = true;
    search_list.push({r, c});
    while (!search_list.empty()) {
      auto search_item = search_list.front();
      search_list.pop();
      for (auto direction_item : directions_) {
        int new_item_r = search_item.first + direction_item.first;
        int new_item_c = search_item.second + direction_item.second;
        if (new_item_r < 0 || new_item_c < 0 || new_item_r >= rows ||
            new_item_c >= cols) {
          continue;
        }
        if (grid[new_item_r][new_item_c] == '1' &&
            !visited[new_item_r][new_item_c]) {
          search_list.push({new_item_r, new_item_c});
          visited[new_item_r][new_item_c] = true;
        }
      }
    }
  }
};

int main() {

  vector<vector<char>> grid{{'1', '1', '1', '1', '0'},
                            {'1', '1', '0', '1', '0'},
                            {'1', '1', '0', '0', '0'},
                            {'0', '0', '0', '0', '0'}};
  Solution sol{};
  auto island_count = sol.numIslands(grid);
  cout << island_count << endl;

  vector<vector<char>> grid2{{'1', '1', '0', '0', '0'},
                             {'1', '1', '0', '0', '0'},
                             {'0', '0', '1', '0', '0'},
                             {'0', '0', '0', '1', '1'}};

  auto island_count2 = sol.numIslands(grid2);
  cout << island_count2 << endl;
  return 0;
}
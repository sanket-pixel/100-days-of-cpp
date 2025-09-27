#include <iostream>
#include <queue>

using namespace std;
struct TreeNode {
  int value;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
  TreeNode(int value, TreeNode *left, TreeNode *right)
      : val(value), left(left), right(right) {}
};

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> lever_order;
    if (root == nullptr) {
      return lever_order;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int l_size = q.size();
      vector<int> level_elements;
      for (int i = 0; i < l_size; i++) {
        TreeNode *c = q.front();
        q.pop();
        level_elements.push_back(c->val);
        if (c->left) {
          q.push(c->left);
        }
        if (c->right) {
          q.push(c->right);
        }
      }
      lever_order.push_back(level_elements);
    }
    return lever_order;
  }
};
int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
  Solution sol;
  vector<vector<int>> level_order = sol.levelOrder(root);
  for (const auto l : level_order) {
    for (const int c : l) {
      std::cout << c << " ";
    }
    std::cout << std::endl;
  }
}
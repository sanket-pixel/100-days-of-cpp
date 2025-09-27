#include <iostream>
#include <queue>

struct TreeNode {
  int value;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : value(0), left(nullptr), right(nullptr) {}
  TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
  TreeNode(int value, TreeNode *left, TreeNode *right)
      : value(value), left(left), right(right) {}
};

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    std::queue<TreeNode *> q;
    q.push(root);
    int max_depth = 0;
    while (!q.empty()) {
      int q_size = q.size();
      max_depth += 1;
      for (int i = 0; i < q_size; i++) {
        TreeNode *c = q.front();
        q.pop();
        if (c->left) {
          q.push(c->left);
        }
        if (c->right) {
          q.push(c->right);
        }
      }
    }
    return max_depth;
  }
};
int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  TreeNode *r = new TreeNode(20);
  r->left = new TreeNode(15);
  r->right = new TreeNode(7);
  root->right = r;
  Solution sol;
  int max_depth = sol.maxDepth(root);
  std::cout << max_depth << std::endl;
  return 0;
}
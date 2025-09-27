#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {}
};

class Solution {
public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    std::queue<TreeNode *, int> q;
    int d = 1;
    q.push(root);
    while (!q.empty()) {
      int d_size = q.size();
      for (int i = 0; i < d_size; i++) {
        TreeNode *c = q.front();
        q.pop();
        if (c->left == nullptr && c->right == nullptr) {
          return d;
        }
        if (c->left) {
          q.push(c->left);
        }
        if (c->right) {
          q.push(c->right);
        }
      }
      d++;
    }
    return d;
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
  int min_d = sol.minDepth(root);
  std::cout << min_d << std::endl;
}

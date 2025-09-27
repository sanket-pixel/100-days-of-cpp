#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) {
      return false;
    }
    stack<std::pair<TreeNode *, int>> s;
    s.push({root, root->val});
    while (!s.empty()) {
      TreeNode *c = s.top().first;
      int current_sum = s.top().second;
      s.pop();
      if (!c->left && !c->right) {
        if (current_sum == targetSum) {
          return true;
        }
      }
      if (c->right) {
        s.emplace(c->right, c->right->val + current_sum);
      }
      if (c->left) {
        s.emplace(c->left, c->left->val + current_sum);
      }
    }
    return false;
  }

  bool hasPathSumR(TreeNode *root, int targetSum) {
    if (!root) {
      return false;
    }
    if (!root->left && !root->right) {
      if (targetSum == root->val) {
        return true;
      }
    }
    return (hasPathSumR(root->left, targetSum - root->val) ||
            hasPathSumR(root->right, targetSum - root->val));
  }
};
int main() {
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->left->left = new TreeNode(11);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  root->right = new TreeNode(8);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->right->right->right = new TreeNode(1);
  int target = 158;
  Solution sol;
  bool ans = sol.hasPathSumR(root, target);
  if (ans) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
}
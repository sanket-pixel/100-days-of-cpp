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
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) {
      root = new TreeNode(val);
    }
    if (val < root->val) {
      root->left = insertIntoBST(root->left, val);
    }
    if (val > root->val) {
      root->right = insertIntoBST(root->right, val);
    }
    return root;
  }
};

int main() {
  TreeNode *root = new TreeNode(4);

  root->left = new TreeNode(2);
  root->right = new TreeNode(7);

  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  Solution sol;
  TreeNode *lca = sol.insertIntoBST(root, 5);
  std::cout << lca->val << std::endl;
}
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
  TreeNode *invertTree(TreeNode *root) {
    if (root != nullptr) {
      TreeNode *temp = root->left;
      root->left = invertTree(root->right);
      root->right = invertTree(temp);
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

  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(9);

  Solution sol;
  TreeNode *root_inv = sol.invertTree(root);
  std::cout << "Done" << std::endl;
}
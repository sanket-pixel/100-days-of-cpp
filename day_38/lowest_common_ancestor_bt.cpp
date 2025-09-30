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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr) {
      return root;
    }
    if (root->val == p->val || root->val == q->val) {
      return root;
    }
    TreeNode *left_lca = lowestCommonAncestor(root->left, p, q);
    TreeNode *right_lca = lowestCommonAncestor(root->right, p, q);

    if (left_lca != nullptr && right_lca != nullptr) {
      return root;
    }
    if (left_lca != nullptr) {
      return left_lca;
    }
    if (right_lca != nullptr) {
      return right_lca;
    }
    return nullptr;
  }
};

int main() {
  TreeNode *root = new TreeNode(3);

  root->left = new TreeNode(5);
  root->right = new TreeNode(1);

  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);

  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);

  Solution sol;
  TreeNode *lca =
      sol.lowestCommonAncestor(root, new TreeNode(6), new TreeNode(4));
  std::cout << lca->val << std::endl;
}
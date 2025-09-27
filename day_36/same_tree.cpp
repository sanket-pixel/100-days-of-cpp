#include <iostream>
#include <queue>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr ^ q == nullptr) {
      return false;
    }
    queue<TreeNode *> p_items;
    queue<TreeNode *> q_items;
    p_items.push(p);
    q_items.push(q);
    while (!p_items.empty() && !q_items.empty()) {
      int p_size = p_items.size();
      int q_size = q_items.size();
      if (p_size != q_size) {
        return false;
      }
      for (int i = 0; i < p_size; i++) {
        TreeNode *p_c = p_items.front();
        TreeNode *q_c = q_items.front();
        p_items.pop();
        q_items.pop();
        if (p_c->val != q_c->val) {
          return false;
        }
        if (p_c->left != nullptr ^ q_c->left != nullptr) {
          return false;
        }
        if (p_c->right != nullptr ^ q_c->right != nullptr) {
          return false;
        }
        if (p_c->left && q_c->left) {
          if (p_c->left->val == q_c->left->val) {
            p_items.push(p_c->left);
            q_items.push(q_c->left);
          } else {
            return false;
          }
        }
        if (p_c->right && q_c->right) {
          if (p_c->right->val == q_c->right->val) {
            p_items.push(p_c->right);
            q_items.push(q_c->right);
          } else {
            return false;
          }
        }
      }
    }
    return true;
  }
};
int main() {
  TreeNode *p = new TreeNode(12);
  p->right = new TreeNode(-72);
  // p->right = new TreeNode(3);

  TreeNode *q = new TreeNode(12);
  q->right = new TreeNode(60);
  // q->right = new TreeNode(3);

  Solution sol;
  bool ans = sol.isSameTree(p, q);
  if (ans) {
    std::cout << "Same" << std::endl;
  } else {
    std::cout << "Not same " << std::endl;
  }
}
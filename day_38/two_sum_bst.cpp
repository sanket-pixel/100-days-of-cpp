#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution {
private:
  unordered_set<int> seen;

public:
  bool findTarget(TreeNode *root, int target) {
    if (!root) {
      return false;
    }
    int diff = target - root->val;
    if (seen.find(diff) == seen.end()) {
      seen.insert(root->val);
      bool l = findTarget(root->left, target);
      bool r = findTarget(root->right, target);
      return l || r;
    } else {
      return true;
    }
  }
};

int main() {
  TreeNode *root = new TreeNode(5);

  root->left = new TreeNode(3);
  root->right = new TreeNode(6);

  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);

  root->left->right->left = new TreeNode(2);
  root->left->right->right = new TreeNode(4);

  root->right->left = new TreeNode(7);

  Solution sol;
  bool two_sum = sol.findTarget(root, 100);
  if (two_sum) {
    std::cout << "Yes";
  } else {
    std::cout << "No";
  }
}
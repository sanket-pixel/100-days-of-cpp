#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    int middle = nums.size() / 2;
    TreeNode *root = new TreeNode(nums[middle]);
    if (nums.size() == 1) {
      return root;
    }
    vector<int> nums_left(nums.begin(), nums.begin() + middle);
    root->left = sortedArrayToBST(nums_left);
    if (nums.size() > 2) {
      vector<int> nums_right(nums.begin() + middle + 1, nums.end());
      root->right = sortedArrayToBST(nums_right);
    }
    return root;
  }
};

int main() {
  vector<int> nums = {-10, -3, 0, 5, 9};
  Solution sol;
  TreeNode *root = sol.sortedArrayToBST(nums);
  std::cout << "here" << std::endl;
}
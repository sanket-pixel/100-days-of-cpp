#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int value):val(value),left(nullptr),right(nullptr){}
};

class Solution{
public:
  int max_len;
  int Height(TreeNode* root){
    if(root==nullptr){
      return 0;
    }
    int left_height =  Height(root->left);
    int right_height =  Height(root->right);
    int current_path_len = left_height+right_height;
    max_len = max(max_len,current_path_len);
    return max(left_height,right_height) + 1;
  }
  int diameterOfBinaryTree(TreeNode* root) {
    max_len=0;
    int h = Height(root);
    return max_len;
  }
};

int main(){
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  // root->left->left = new TreeNode(4);
  // root->left->right = new TreeNode(5);
  // root->right = new TreeNode(3);
  Solution sol;
  int d = sol.diameterOfBinaryTree(root);
  std::cout << d << std::endl;
}
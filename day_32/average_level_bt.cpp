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
  int levels(TreeNode *node, int l) {
    if (node->left != nullptr && node->right != nullptr) {
      l = 1 + std::max(levels(node->left, l), levels(node->right, l));
    } else if (node->left != nullptr) {
      l = 1 + levels(node->left, l);
    } else if (node->right != nullptr) {
      l = 1 + levels(node->right, l);
    }
    return l;
  }

  void sum_count(TreeNode *node, std::vector<double> &sum,
                 std::vector<size_t> &count, int l) {
    sum[l] += node->val;
    count[l] += 1;
    if (node->left != nullptr && node->right != nullptr) {
      sum_count(node->left, sum, count, l + 1);
      sum_count(node->right, sum, count, l + 1);
    } else if (node->right != nullptr) {
      sum_count(node->right, sum, count, l + 1);
    } else if (node->left != nullptr) {
      sum_count(node->left, sum, count, l + 1);
    }
  }

  std::vector<double> averageOfLevels2(TreeNode *root) {
    int total_levels = levels(root, 0) + 1;
    std::vector<double> sum(total_levels, 0);
    std::vector<size_t> count(total_levels, 0);
    std::vector<double> avg(total_levels, 0);
    sum_count(root, sum, count, 0);
    for (int i = 0; i < total_levels; i++) {
      avg[i] = sum[i] / count[i];
    }
    return avg;
  }

  std::vector<double> averageOfLevels(TreeNode *root) {
    std::queue<TreeNode *> q;
    std::vector<double> avg;
    q.push(root);
    while (!q.empty()) {
      int level_size = q.size();
      double sum = 0.0;
      for (int i = 0; i < level_size; i++) {
        TreeNode *c = q.front();
        q.pop();
        sum += c->val;
        if (c->left) {
          q.push(c->left);
        }
        if (c->right) {
          q.push(c->right);
        }
      }
      avg.push_back(sum / level_size);
    }
    return avg;
  }
};

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->left->left = new TreeNode(15);
  root->left->right = new TreeNode(7);
  Solution sol;
  auto avg = sol.averageOfLevels(root);
  std::cout << avg.size() << std::endl;
}

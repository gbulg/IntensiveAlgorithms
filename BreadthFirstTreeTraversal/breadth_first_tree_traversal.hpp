#pragma once

#include <vector>

// https://leetcode.com/problems/binary-tree-level-order-traversal/

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> result;

    std::vector<int> cur_level;
    std::queue<TreeNode *> q;
    if (root) q.push(root);

    while(!q.empty()) {
        int level_size = q.size();
        for (int i = 0; i < level_size; ++i) {
            TreeNode *cur = q.front();
            q.pop();

            cur_level.push_back(cur->val);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        result.push_back(cur_level);
        cur_level.clear();
    }
    return result;
  }
};
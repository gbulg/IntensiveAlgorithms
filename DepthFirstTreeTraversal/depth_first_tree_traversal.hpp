#pragma once

#include <cstddef>
#include <vector>

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void FillNeighbours(TreeNode* root, std::unordered_map<TreeNode *, std::vector<TreeNode *>>& neighbours) {
        if (root->left) {
            neighbours[root].push_back(root->left);
            neighbours[root->left].push_back(root);
            FillNeighbours(root->left, neighbours);
        }
        if (root->right) {
            neighbours[root].push_back(root->right);
            neighbours[root->right].push_back(root);
            FillNeighbours(root->right, neighbours);
        }
    }

    void dfs(TreeNode* node, int dist, std::vector<int>& result, std::unordered_map<TreeNode *, int>& visited, std::unordered_map<TreeNode *, std::vector<TreeNode *>>& neighbours) {
        visited[node] = 1;
        if (dist == 0) {
            result.push_back(node->val);
            return;
        }
        for (auto neighbour : neighbours[node]) {
            if (visited[neighbour]) continue;
            dfs(neighbour, dist - 1, result, visited, neighbours);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        std::unordered_map<TreeNode *, std::vector<TreeNode *>> neighbours;
        FillNeighbours(root, neighbours);
        
        std::unordered_map<TreeNode *, int> visited;
        std::vector<int> result;
        dfs(target, k, result, visited, neighbours);

        return result;
    }
};

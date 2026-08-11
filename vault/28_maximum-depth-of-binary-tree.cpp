// 28. Maximum Depth of Binary Tree   [Easy]
// Topic: Trees
// LeetCode: https://leetcode.com/problems/maximum-depth-of-binary-tree/
//
// Approach: 1 + max depth of the two subtrees.
// Time: O(n)   Space: O(h)

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

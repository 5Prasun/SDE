// 33. Validate Binary Search Tree   [Medium]
// Topic: Trees / BST
// LeetCode: https://leetcode.com/problems/validate-binary-search-tree/
//
// Approach: Recurse carrying valid (lo, hi) bounds for each node.
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
    bool validate(TreeNode* node, long long lo, long long hi) {
        if (!node) return true;
        if (node->val <= lo || node->val >= hi) return false;
        return validate(node->left, lo, node->val) &&
               validate(node->right, node->val, hi);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

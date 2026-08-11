// 30. Subtree of Another Tree   [Easy]
// Topic: Trees
// LeetCode: https://leetcode.com/problems/subtree-of-another-tree/
//
// Approach: At every node test sameTree against the candidate subtree.
// Time: O(n*m)   Space: O(h)

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
    bool same(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b || a->val != b->val) return false;
        return same(a->left, b->left) && same(a->right, b->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;
        if (same(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

// 31. Lowest Common Ancestor of a BST   [Medium]
// Topic: Trees / BST
// LeetCode: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
//
// Approach: Walk down; the split point where p and q diverge is the LCA.
// Time: O(h)   Space: O(1)

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val) root = root->left;
            else if (p->val > root->val && q->val > root->val) root = root->right;
            else return root;
        }
        return nullptr;
    }
};

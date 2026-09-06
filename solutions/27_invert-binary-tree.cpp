// 27. Invert Binary Tree   [Easy]
// Topic: Trees
// LeetCode: https://leetcode.com/problems/invert-binary-tree/
//
// Approach: Swap children, recurse on both sides.
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

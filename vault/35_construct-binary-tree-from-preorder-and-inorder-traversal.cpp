// 35. Construct Binary Tree from Preorder and Inorder   [Medium]
// Topic: Trees
// LeetCode: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
//
// Approach: Preorder gives roots in order; inorder index splits left/right.
// Time: O(n)   Space: O(n)

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    unordered_map<int,int> idx;
    int pre = 0;
    TreeNode* build(vector<int>& preorder, int l, int r) {
        if (l > r) return nullptr;
        int rootVal = preorder[pre++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = idx[rootVal];
        root->left = build(preorder, l, mid - 1);
        root->right = build(preorder, mid + 1, r);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < (int)inorder.size(); ++i) idx[inorder[i]] = i;
        return build(preorder, 0, inorder.size() - 1);
    }
};

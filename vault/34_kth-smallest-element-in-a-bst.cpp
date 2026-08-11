// 34. Kth Smallest Element in a BST   [Medium]
// Topic: Trees / BST
// LeetCode: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
//
// Approach: Iterative in-order traversal; the k-th popped node is the answer.
// Time: O(h+k)   Space: O(h)

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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) { st.push(cur); cur = cur->left; }
            cur = st.top(); st.pop();
            if (--k == 0) return cur->val;
            cur = cur->right;
        }
        return -1;
    }
};

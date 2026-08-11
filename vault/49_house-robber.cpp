// 49. House Robber   [Medium]
// Topic: Dynamic Programming
// LeetCode: https://leetcode.com/problems/house-robber/
//
// Approach: Rolling DP: best = max(skip, rob current + best two back).
// Time: O(n)   Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, cur = 0;
        for (int x : nums) { int t = max(cur, prev + x); prev = cur; cur = t; }
        return cur;
    }
};

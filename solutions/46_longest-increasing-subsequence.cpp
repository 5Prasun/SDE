// 46. Longest Increasing Subsequence   [Medium]
// Topic: Dynamic Programming
// LeetCode: https://leetcode.com/problems/longest-increasing-subsequence/
//
// Approach: Patience sorting; binary-search the tails array.
// Time: O(n log n)   Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) tails.push_back(x);
            else *it = x;
        }
        return tails.size();
    }
};

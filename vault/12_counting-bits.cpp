// 12. Counting Bits   [Easy]
// Topic: Bit Manipulation / DP
// LeetCode: https://leetcode.com/problems/counting-bits/
//
// Approach: dp[i] = dp[i>>1] + (i & 1).
// Time: O(n)   Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) dp[i] = dp[i >> 1] + (i & 1);
        return dp;
    }
};

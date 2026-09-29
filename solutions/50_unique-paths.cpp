// 50. Unique Paths   [Medium]
// Topic: Dynamic Programming
// LeetCode: https://leetcode.com/problems/unique-paths/
//
// Approach: 1D DP row; dp[j] += dp[j-1] accumulates path counts.
// Time: O(m*n)   Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[j] += dp[j-1];
        return dp[n-1];
    }
};

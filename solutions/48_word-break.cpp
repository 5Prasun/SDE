// 48. Word Break   [Medium]
// Topic: Dynamic Programming
// LeetCode: https://leetcode.com/problems/word-break/
//
// Approach: dp[i] true if some split point j has dp[j] and s[j..i] in dict.
// Time: O(n^2)   Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < i; ++j)
                if (dp[j] && dict.count(s.substr(j, i - j))) { dp[i] = true; break; }
        return dp[n];
    }
};

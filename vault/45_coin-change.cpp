// 45. Coin Change   [Medium]
// Topic: Dynamic Programming
// LeetCode: https://leetcode.com/problems/coin-change/
//
// Approach: Unbounded knapsack; dp[a] = min coins to make amount a.
// Time: O(amount*coins)   Space: O(amount)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int a = 1; a <= amount; ++a)
            for (int c : coins)
                if (c <= a) dp[a] = min(dp[a], dp[a - c] + 1);
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

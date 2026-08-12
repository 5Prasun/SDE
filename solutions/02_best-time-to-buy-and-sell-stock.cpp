// 2. Best Time to Buy and Sell Stock   [Easy]
// Topic: Arrays / Sliding Window
// LeetCode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//
// Approach: Track the minimum price so far and the best profit against it.
// Time: O(n)   Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = INT_MAX, best = 0;
        for (int p : prices) {
            minP = min(minP, p);
            best = max(best, p - minP);
        }
        return best;
    }
};

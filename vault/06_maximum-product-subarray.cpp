// 6. Maximum Product Subarray   [Medium]
// Topic: Dynamic Programming
// LeetCode: https://leetcode.com/problems/maximum-product-subarray/
//
// Approach: Track both running max and min (negatives flip sign).
// Time: O(n)   Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int best = nums[0], curMax = nums[0], curMin = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) {
            int a = nums[i], b = curMax * nums[i], c = curMin * nums[i];
            curMax = max({a, b, c});
            curMin = min({a, b, c});
            best = max(best, curMax);
        }
        return best;
    }
};

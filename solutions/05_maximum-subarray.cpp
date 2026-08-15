// 5. Maximum Subarray   [Medium]
// Topic: Dynamic Programming
// LeetCode: https://leetcode.com/problems/maximum-subarray/
//
// Approach: Kadane: extend the running sum or restart at the current element.
// Time: O(n)   Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0], best = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) {
            cur = max(nums[i], cur + nums[i]);
            best = max(best, cur);
        }
        return best;
    }
};

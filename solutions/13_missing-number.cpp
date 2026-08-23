// 13. Missing Number   [Easy]
// Topic: Math / Bit
// LeetCode: https://leetcode.com/problems/missing-number/
//
// Approach: Expected sum 0..n minus actual sum.
// Time: O(n)   Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long total = (long long)n * (n + 1) / 2;
        for (int x : nums) total -= x;
        return (int)total;
    }
};

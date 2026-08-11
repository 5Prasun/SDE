// 10. Container With Most Water   [Medium]
// Topic: Two Pointers
// LeetCode: https://leetcode.com/problems/container-with-most-water/
//
// Approach: Two pointers from the ends; move the shorter wall inward.
// Time: O(n)   Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, best = 0;
        while (l < r) {
            best = max(best, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) ++l; else --r;
        }
        return best;
    }
};

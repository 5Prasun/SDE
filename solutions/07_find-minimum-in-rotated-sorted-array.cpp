// 7. Find Minimum in Rotated Sorted Array   [Medium]
// Topic: Binary Search
// LeetCode: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
//
// Approach: Binary search the unsorted half toward the pivot (minimum).
// Time: O(log n)   Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi]) lo = mid + 1;
            else hi = mid;
        }
        return nums[lo];
    }
};

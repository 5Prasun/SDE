// 1. Two Sum   [Easy]
// Topic: Arrays / Hashing
// LeetCode: https://leetcode.com/problems/two-sum/
//
// Approach: Hash map of value->index; for each element look up the complement.
// Time: O(n)   Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        for (int i = 0; i < (int)nums.size(); ++i) {
            int need = target - nums[i];
            if (seen.count(need)) return {seen[need], i};
            seen[nums[i]] = i;
        }
        return {};
    }
};

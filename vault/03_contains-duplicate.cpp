// 3. Contains Duplicate   [Easy]
// Topic: Arrays / Hashing
// LeetCode: https://leetcode.com/problems/contains-duplicate/
//
// Approach: Insert into a hash set; a failed insert means a duplicate.
// Time: O(n)   Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int x : nums) if (!s.insert(x).second) return true;
        return false;
    }
};

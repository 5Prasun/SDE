// 11. Number of 1 Bits   [Easy]
// Topic: Bit Manipulation
// LeetCode: https://leetcode.com/problems/number-of-1-bits/
//
// Approach: Repeatedly clear the lowest set bit with n &= n-1.
// Time: O(#bits)   Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c = 0;
        while (n) { n &= (n - 1); ++c; }
        return c;
    }
};

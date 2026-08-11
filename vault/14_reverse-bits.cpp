// 14. Reverse Bits   [Easy]
// Topic: Bit Manipulation
// LeetCode: https://leetcode.com/problems/reverse-bits/
//
// Approach: Shift result left, pull in the lowest bit of n, repeat 32x.
// Time: O(1)   Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            res = (res << 1) | (n & 1);
            n >>= 1;
        }
        return res;
    }
};

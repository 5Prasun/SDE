// 44. Climbing Stairs   [Easy]
// Topic: Dynamic Programming
// LeetCode: https://leetcode.com/problems/climbing-stairs/
//
// Approach: Fibonacci recurrence: ways(n) = ways(n-1) + ways(n-2).
// Time: O(n)   Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; }
        return b;
    }
};

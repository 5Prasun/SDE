// 17. Minimum Window Substring   [Hard]
// Topic: Sliding Window
// LeetCode: https://leetcode.com/problems/minimum-window-substring/
//
// Approach: Expand to cover all needed chars, then shrink to minimise.
// Time: O(n)   Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        vector<int> need(128, 0);
        for (char c : t) need[(int)c]++;
        int required = t.size(), l = 0, bestLen = INT_MAX, bestStart = 0;
        for (int r = 0; r < (int)s.size(); ++r) {
            if (need[(int)s[r]]-- > 0) required--;
            while (required == 0) {
                if (r - l + 1 < bestLen) { bestLen = r - l + 1; bestStart = l; }
                if (need[(int)s[l]]++ == 0) required++;
                ++l;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};

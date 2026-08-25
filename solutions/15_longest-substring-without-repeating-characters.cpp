// 15. Longest Substring Without Repeating Characters   [Medium]
// Topic: Sliding Window
// LeetCode: https://leetcode.com/problems/longest-substring-without-repeating-characters/
//
// Approach: Sliding window; jump the left bound past the last seen duplicate.
// Time: O(n)   Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int start = 0, best = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            unsigned char ch = s[i];
            if (last[ch] >= start) start = last[ch] + 1;
            last[ch] = i;
            best = max(best, i - start + 1);
        }
        return best;
    }
};

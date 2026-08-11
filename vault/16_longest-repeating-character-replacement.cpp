// 16. Longest Repeating Character Replacement   [Medium]
// Topic: Sliding Window
// LeetCode: https://leetcode.com/problems/longest-repeating-character-replacement/
//
// Approach: Window valid while (len - maxFreq) <= k.
// Time: O(n)   Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int l = 0, maxFreq = 0, best = 0;
        for (int r = 0; r < (int)s.size(); ++r) {
            maxFreq = max(maxFreq, ++cnt[s[r] - 'A']);
            while ((r - l + 1) - maxFreq > k) --cnt[s[l++] - 'A'];
            best = max(best, r - l + 1);
        }
        return best;
    }
};

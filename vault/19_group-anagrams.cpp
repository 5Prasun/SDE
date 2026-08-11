// 19. Group Anagrams   [Medium]
// Topic: Hashing
// LeetCode: https://leetcode.com/problems/group-anagrams/
//
// Approach: Key each word by its sorted form; bucket into a map.
// Time: O(n k log k)   Space: O(n k)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& kv : groups) res.push_back(move(kv.second));
        return res;
    }
};

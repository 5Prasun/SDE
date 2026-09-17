// 38. Combination Sum   [Medium]
// Topic: Backtracking
// LeetCode: https://leetcode.com/problems/combination-sum/
//
// Approach: DFS choosing candidates with reuse; recurse from the same index.
// Time: O(2^t)   Space: O(t)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> cur;
    void dfs(vector<int>& c, int start, int target) {
        if (target == 0) { res.push_back(cur); return; }
        for (int i = start; i < (int)c.size(); ++i) {
            if (c[i] > target) break;           // sorted -> prune
            cur.push_back(c[i]);
            dfs(c, i, target - c[i]);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }
};

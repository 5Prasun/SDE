// 43. Pacific Atlantic Water Flow   [Medium]
// Topic: Graphs / DFS
// LeetCode: https://leetcode.com/problems/pacific-atlantic-water-flow/
//
// Approach: DFS inward from each ocean border; answer is the intersection.
// Time: O(m*n)   Space: O(m*n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int rows, cols;
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& ocean, int r, int c, int prev) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || ocean[r][c] || h[r][c] < prev) return;
        ocean[r][c] = true;
        dfs(h, ocean, r+1, c, h[r][c]); dfs(h, ocean, r-1, c, h[r][c]);
        dfs(h, ocean, r, c+1, h[r][c]); dfs(h, ocean, r, c-1, h[r][c]);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size(); cols = heights[0].size();
        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));
        for (int r = 0; r < rows; ++r) { dfs(heights, pac, r, 0, INT_MIN); dfs(heights, atl, r, cols-1, INT_MIN); }
        for (int c = 0; c < cols; ++c) { dfs(heights, pac, 0, c, INT_MIN); dfs(heights, atl, rows-1, c, INT_MIN); }
        vector<vector<int>> res;
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (pac[r][c] && atl[r][c]) res.push_back({r, c});
        return res;
    }
};

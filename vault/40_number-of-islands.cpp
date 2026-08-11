// 40. Number of Islands   [Medium]
// Topic: Graphs / DFS
// LeetCode: https://leetcode.com/problems/number-of-islands/
//
// Approach: Flood-fill each unvisited land cell; count the fills.
// Time: O(m*n)   Space: O(m*n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= (int)grid.size() || c >= (int)grid[0].size() || grid[r][c] != '1') return;
        grid[r][c] = '0';
        dfs(grid, r+1, c); dfs(grid, r-1, c); dfs(grid, r, c+1); dfs(grid, r, c-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int r = 0; r < (int)grid.size(); ++r)
            for (int c = 0; c < (int)grid[0].size(); ++c)
                if (grid[r][c] == '1') { ++count; dfs(grid, r, c); }
        return count;
    }
};

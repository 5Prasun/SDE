// 39. Word Search   [Medium]
// Topic: Backtracking / DFS
// LeetCode: https://leetcode.com/problems/word-search/
//
// Approach: DFS from each cell, marking visited, backtracking on return.
// Time: O(m*n*4^L)   Space: O(L)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int rows, cols;
    bool dfs(vector<vector<char>>& board, const string& word, int i, int r, int c) {
        if (i == (int)word.size()) return true;
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[i]) return false;
        char tmp = board[r][c];
        board[r][c] = '#';
        bool found = dfs(board, word, i+1, r+1, c) || dfs(board, word, i+1, r-1, c) ||
                     dfs(board, word, i+1, r, c+1) || dfs(board, word, i+1, r, c-1);
        board[r][c] = tmp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size(); cols = board[0].size();
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (dfs(board, word, 0, r, c)) return true;
        return false;
    }
};

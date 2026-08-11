// 42. Course Schedule   [Medium]
// Topic: Graphs / Topological Sort
// LeetCode: https://leetcode.com/problems/course-schedule/
//
// Approach: Kahn's algorithm; finishable iff all nodes get processed.
// Time: O(V+E)   Space: O(V+E)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto& p : prerequisites) { adj[p[1]].push_back(p[0]); indeg[p[0]]++; }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) if (indeg[i] == 0) q.push(i);
        int done = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ++done;
            for (int v : adj[u]) if (--indeg[v] == 0) q.push(v);
        }
        return done == numCourses;
    }
};

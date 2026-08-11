// 41. Clone Graph   [Medium]
// Topic: Graphs / DFS
// LeetCode: https://leetcode.com/problems/clone-graph/
//
// Approach: DFS with a map from original node to its clone.
// Time: O(V+E)   Space: O(V)

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0) {}
    Node(int _val) : val(_val) {}
};

class Solution {
    unordered_map<Node*, Node*> mp;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (mp.count(node)) return mp[node];
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for (Node* nb : node->neighbors)
            clone->neighbors.push_back(cloneGraph(nb));
        return clone;
    }
};

// 37. Top K Frequent Elements   [Medium]
// Topic: Heap / Bucket Sort
// LeetCode: https://leetcode.com/problems/top-k-frequent-elements/
//
// Approach: Count frequencies, bucket by count, read the top buckets.
// Time: O(n)   Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        for (int x : nums) cnt[x]++;
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for (auto& kv : cnt) buckets[kv.second].push_back(kv.first);
        vector<int> res;
        for (int i = n; i >= 1 && (int)res.size() < k; --i)
            for (int v : buckets[i]) {
                res.push_back(v);
                if ((int)res.size() == k) break;
            }
        return res;
    }
};

// 36. Find Median from Data Stream   [Hard]
// Topic: Heap / Design
// LeetCode: https://leetcode.com/problems/find-median-from-data-stream/
//
// Approach: Two heaps balanced so the tops straddle the median.
// Time: O(log n) add   Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> lo;                              // max-heap (lower half)
    priority_queue<int, vector<int>, greater<int>> hi;   // min-heap (upper half)
public:
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top()); lo.pop();
        if (hi.size() > lo.size()) { lo.push(hi.top()); hi.pop(); }
    }
    double findMedian() {
        if (lo.size() > hi.size()) return lo.top();
        return (lo.top() + hi.top()) / 2.0;
    }
};

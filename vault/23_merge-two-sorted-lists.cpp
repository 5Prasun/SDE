// 23. Merge Two Sorted Lists   [Easy]
// Topic: Linked List
// LeetCode: https://leetcode.com/problems/merge-two-sorted-lists/
//
// Approach: Dummy head; splice the smaller front node each step.
// Time: O(n+m)   Space: O(1)

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (a && b) {
            if (a->val <= b->val) { tail->next = a; a = a->next; }
            else { tail->next = b; b = b->next; }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return dummy.next;
    }
};

// 26. Reorder List   [Medium]
// Topic: Linked List
// LeetCode: https://leetcode.com/problems/reorder-list/
//
// Approach: Find middle, reverse second half, then weave the two halves.
// Time: O(n)   Space: O(1)

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) { slow = slow->next; fast = fast->next->next; }
        ListNode *second = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr;
        while (second) { ListNode* nxt = second->next; second->next = prev; prev = second; second = nxt; }
        ListNode *first = head; second = prev;
        while (second) {
            ListNode *t1 = first->next, *t2 = second->next;
            first->next = second; second->next = t1;
            first = t1; second = t2;
        }
    }
};

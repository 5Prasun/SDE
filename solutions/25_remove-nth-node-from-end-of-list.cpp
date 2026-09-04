// 25. Remove Nth Node From End of List   [Medium]
// Topic: Linked List
// LeetCode: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//
// Approach: Two pointers n apart; when fast hits the end, slow is before target.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0); dummy.next = head;
        ListNode *fast = &dummy, *slow = &dummy;
        for (int i = 0; i < n; ++i) fast = fast->next;
        while (fast->next) { fast = fast->next; slow = slow->next; }
        slow->next = slow->next->next;
        return dummy.next;
    }
};

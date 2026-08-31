// 21. Reverse Linked List   [Easy]
// Topic: Linked List
// LeetCode: https://leetcode.com/problems/reverse-linked-list/
//
// Approach: Iteratively re-point each node to its predecessor.
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
};

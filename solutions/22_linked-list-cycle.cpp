// 22. Linked List Cycle   [Easy]
// Topic: Linked List
// LeetCode: https://leetcode.com/problems/linked-list-cycle/
//
// Approach: Floyd's tortoise and hare; they meet iff a cycle exists.
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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

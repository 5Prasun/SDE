// 20. Valid Parentheses   [Easy]
// Topic: Stack
// LeetCode: https://leetcode.com/problems/valid-parentheses/
//
// Approach: Push openers, match each closer with the stack top.
// Time: O(n)   Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') st.push(c);
            else {
                if (st.empty()) return false;
                char top = st.top(); st.pop();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) return false;
            }
        }
        return st.empty();
    }
};

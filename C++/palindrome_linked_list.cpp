#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Runtime: beats 67.08 of users with C++
 * Memory: beats 39.09% of users with C++
 * Daily problem (Streak 38)
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::vector<char> values;

        while(head) {
            values.push_back(head->val);
            head = head->next;
        }

        int i = 0, j = values.size() - 1;

        while(i < j && values[i] == values[j]) {i++; j--;}

        return values[i] == values[j];
    }
};
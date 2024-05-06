#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Runtime: beats 86.97% of users with C++
 * Memory: beats 90.66% of users with C++
 * Daily problem (Streak 83)
*/

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (!head->next) return head;

        ListNode *prev, *curr, *tmp;
        prev = head; curr = head->next;

        while (curr) {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        head->next = NULL;
        head = prev;

        prev = head;
        curr = head->next;

        while (curr)
            if (curr->val < prev->val)
                curr = curr->next;
            else {
                tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

        head->next = NULL;
        head = prev;

        return head;
    }
};
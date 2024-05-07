#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Runtime: beats 72.88% of users with C++
 * Memory: beats 72.53% of users with C++
 * Daily problem (Streak 84)
*/

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if(head->val > 4) head = new ListNode(0, head);

        ListNode *p = head;

        while(p) {
            p->val = (p->val * 2) % 10;

            if(p->next && p->next->val > 4) p->val++;

            p = p->next;
        }

        return head;
    }
};
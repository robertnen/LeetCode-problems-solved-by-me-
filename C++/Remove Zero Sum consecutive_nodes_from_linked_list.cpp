#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Runtime: beats 90.42% of users with C++
 * Memory: beats 36.48% of users with C++
 * Daily problem (Streak 28)
*/

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefix = 0;
        ListNode node = ListNode(0, head), *p = &node;
        std::unordered_map<int, ListNode*> sums;

        while(p) {
            prefix += p->val;
            sums[prefix] = p;
            p = p->next;
        }

        prefix = 0;
        p = &node;

        while(p) {
            prefix += p->val;
            p->next = sums[prefix]->next;
            p = p->next;
        }

        return node.next;
    }
};
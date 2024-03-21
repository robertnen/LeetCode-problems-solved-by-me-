#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Runtime: beats 56.53% of users with C++
 * Memory: beats 6.68% of users with C++
 * Daily problem (Streak 37)
*/


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *list = NULL, *p;

        if(!head) return head;

        while(head) {
            p = new ListNode(head->val);
            p->next = list;
            list = p;
            head = head->next;
        }

        return list;
    }
};
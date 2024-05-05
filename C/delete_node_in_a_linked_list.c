#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Runtime: beats 100% of users with C
 * Memory: beats 100% of users with C
 * Daily problem (Streak 82)
*/

void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
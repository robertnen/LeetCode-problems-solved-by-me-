#include <stdbool.h>
#include <stdio.h>

struct ListNode {
      int val;
      struct ListNode *next;
  };

/**
 * Runtime: beats 45.69% of users with C
 * Memory: beats 26.22% of users with C
 * Daily problem (Streak 22)
*/

bool hasCycle(struct ListNode *head) {
    if(!head || !head->next) return false;

    struct ListNode *st = head, *nd = head;

    do {
        st = st->next;
        if(nd->next) nd = nd->next->next;
        else return false;
    } while(st != NULL && nd != NULL && st != nd);

    return !(!nd);
}
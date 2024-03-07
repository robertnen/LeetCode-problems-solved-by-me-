struct ListNode {
      int val;
      struct ListNode *next;
  };

/**
 * Runtime: beats 56.04% of users with C
 * Memory: beats 61.50% of users with C
 * Daily problem (Streak 23)
*/

struct ListNode* middleNode(struct ListNode* head) {
    if(!head || !head->next) return head;

    struct ListNode *st = head, *nd = head;

    do {
        if(nd->next) {
            nd = nd->next->next;
            st = st->next;
        } else break;
    } while(nd);

    return st;
}
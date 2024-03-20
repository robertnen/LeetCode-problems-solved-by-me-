struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Runtime: beats 87.31% of users with C++
 * Memory: beats 98.03% of users with C++
 * Daily problem (Streak 36)
*/

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *head = list1, *p, *q, *r;

        a--;

        while(list1 && a--) {
            list1 = list1->next;
            p = list1;
        }

        list1 = head;

        while(list1 && b--) {
            list1 = list1->next;
            q = list1;
        }

        r = list2;

        while(r->next) r = r->next;

        p->next = list2;
        r->next = q->next;

        return head;
    }
};
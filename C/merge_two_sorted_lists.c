#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(!list1) return list2;
    if(!list2) return list1;

    struct ListNode *q;

    if(list1->val > list2->val) {
        q = list1;
        list1 = list2;
        list2 = q;
    }

    struct ListNode *head = list1, *p;

    while(list1 && list2) {
        p = NULL;

        while(list1 && list1->val <= list2->val) {
            p = list1;
            list1 = list1->next;
        }

        p->next = list2;

        q = list1;
        list1 = list2;
        list2 = q;
    }

    return head;
}
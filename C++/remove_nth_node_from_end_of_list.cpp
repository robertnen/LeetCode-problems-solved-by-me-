struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Runtime: beats 19.64% of users with C++
 * Memory: beats 45.90% of users with C++
 * Daily problem (Streak 19)
*/


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *node = head, *tmp;

        char sz = 1;

        while(node) {node = node->next; sz++;}

        sz -= (char) n;
        node = head;

        if(sz == 1) {
            head = head->next;
            delete node;
            return head;
        }

        while(sz-- > 2) node = node->next;

        tmp = node->next;

        node->next = tmp->next;
        delete tmp;

        return head;
    }
};
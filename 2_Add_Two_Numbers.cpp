/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        else {
            ListNode* head = new ListNode(0);
            ListNode *p, *q, *i;
            int numP, numQ;
            p = l1, q = l2, i = head;
            while (p || q) {
                if (p) {
                    numP = p->val;
                    p = p->next;
                }
                else numP = 0;
                if (q) {
                    numQ = q->val;
                    q = q->next;
                }
                else numQ = 0;
                if (p || q || i->val + numP + numQ > 9) i->next = new ListNode((i->val + numP + numQ) / 10);
                i->val = (i->val + numP + numQ) % 10;
                i = i->next;
            }
            return head;
        }
    }
};

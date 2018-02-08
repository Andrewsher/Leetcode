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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p, *phead, *temp1, *temp2;
        p = head;
        phead = head;
        if (p == NULL) return NULL;
        while(p && p->next) {
            temp2 = p->next->next;
            p->next->next = p;
            if(p != head) temp1->next = p->next;
            else phead = p->next;
            p->next = temp2;
            temp1 = p;
            p = temp2;
        }
        return phead;
    }
};

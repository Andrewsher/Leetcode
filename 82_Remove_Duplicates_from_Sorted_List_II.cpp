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
    ListNode* deleteNextNode(ListNode* p) {
        // delete p->next
        if(NULL == p || NULL == p->next) return NULL;
        ListNode* q = p->next;
        p->next = q->next;
        delete q;
        q = NULL;
        return p->next;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p, * q;
        ListNode tmpHead(1);
        tmpHead.next = head;
        p = &tmpHead;
        q = head;
        if(NULL == q) return NULL;      // empty list
        while(NULL != q && NULL != q->next) {
            if(q->val == q->next->val) {
                int num = q->val;
                while(NULL != q && q->val == num) {
                    q = deleteNextNode(p);  // delete q, where q == p->next
                }
            }
            else {
                p = q;
                q = q->next;
            }
        }
        return tmpHead.next;
    }
};
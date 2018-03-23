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
    ListNode* partition(ListNode* head, int x) {
        ListNode tmpHead(0);
        tmpHead.next = head;
        if(NULL == tmpHead.next) return NULL;
        ListNode* preTail = &tmpHead;
        ListNode* fomHead = NULL;
        ListNode* fomTail = NULL;
        ListNode* cur = preTail->next;
        while(NULL != cur) {
            if(cur->val >= x) {
                if(NULL == fomHead) {
                    fomHead = cur;
                    fomTail = cur;
                }
                else {
                    fomTail->next = cur;
                    fomTail = fomTail->next;
                }
            }
            else {
                preTail->next = cur;
                preTail = preTail->next;
            }
            cur = cur->next;
        }
        if(NULL != fomTail) fomTail->next = NULL;
        preTail->next = fomHead;
        return tmpHead.next;
    }
};
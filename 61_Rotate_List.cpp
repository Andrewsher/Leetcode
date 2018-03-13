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
	ListNode* rotateRight(ListNode* head, int k) {
        		if(NULL == head) return NULL;
		if(NULL == head->next) return head;
        
        		// 计算节点总数
        		int sum = 0;
		ListNode* tmp = head;
		while(NULL != tmp) {
			sum++;
			tmp = tmp->next;
		}
		k = k % sum;
		cout << "k = " << k << " sum = " << sum << endl;
        
		if(k <= 0) return head;
        
		// 全部倒置
		head = rotate(head, sum);
        
		// 前k个倒置
		head = rotate(head, k);
        
		// 后sum-k个倒置
		int index = 1;
		tmp = head;
		for(; index < k; index++) tmp = tmp->next;
		tmp->next = rotate(tmp->next, sum - k);
        
		return head;
	}
	ListNode* rotate(ListNode* head, int n) {
		if(NULL == head) return NULL;
		if(NULL == head->next) return head;
        		if(1 >= n) return head;
		// 将以head开头的链表的n个元素倒置
		ListNode* pre = head;
		ListNode* former = head->next;
		ListNode* tmp = former->next;
		for(int i = 0; i < n - 1; i++) {
			tmp = former->next;
			former->next = pre;
			pre = former;
			former = tmp;
			if(NULL == former) break;
			else continue;
		}
		// 相对于外部的关系不变
		head->next = tmp;
        
		return pre;
	}
};
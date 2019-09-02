/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i = 1;
        //手动制造一个表头
        ListNode* tmpHead = new ListNode(0);
        tmpHead->next = head;
        ListNode* start = tmpHead;
        ListNode* end = tmpHead;
        ListNode* tmp = NULL;
        while (i != m) {
        	i += 1;
        	start = start->next;
        	end = end->next;
        }
        while (i != n) {
        	i += 1;
        	end = end->next;
        }
        end = end->next;
        tmp = end->next;
        end->next = NULL;
        end = tmp;

        tmp = reverseList(start);
        start->next = tmp->next;
        while (tmp->next != NULL) {
        	tmp = tmp->next;
        }
        tmp->next = end;

        head = tmpHead->next;
        delete tmpHead;

        return head;
        

    }
private:
	ListNode* reverseList(ListNode* head) {
		if (head->next == NULL) {
			return head;
		}

		ListNode* pre = NULL;
		ListNode* current = head->next;
		ListNode* nextNode = current->next;
		while (nextNode != NULL) {
			current->next = pre;
			pre = current;
			current = nextNode;
			nextNode = nextNode->next;
		}
		current->next = pre;
		head->next = current;
		return head;
	}
};

int main()
{
	//初始化表头
	struct ListNode* head = new struct ListNode(1);
	struct ListNode* x = head;
	//建立链表
	for(int i = 2; i <= 5; i++)
	{
		struct ListNode* tmp = new struct ListNode(i);
		x->next = tmp;
		x = x->next;
	}
	//打印链表
	x = head;
	while(x != NULL)
	{
		cout << x->val << " ";
		x = x->next;
	}
	cout << endl;
	//反转
	Solution* S = new Solution();
	struct ListNode* new_head = S->reverseBetween(head, 2, 4);
	//打印链表
	x = new_head;
	while(x != NULL)
	{
		cout << x->val << ' ';
		x = x->next;
	}
	cout << endl;
	return 0;
}
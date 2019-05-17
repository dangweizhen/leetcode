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
        ListNode* precede_node = head;
        ListNode* follow_node = NULL;
        ListNode* last = NULL;
        ListNode* res = head;
        while(precede_node != NULL && precede_node->next != NULL)
        {
        	//+1
        	follow_node = precede_node;
        	precede_node = precede_node->next;
        	//swap
        	if(last != NULL)
        		last->next = precede_node;
        	follow_node->next = precede_node->next;
        	precede_node->next = follow_node;
        	last = follow_node;
        	ListNode* tmp = follow_node;
        	follow_node=precede_node;
        	precede_node=tmp;
            if(res == head) res = follow_node;
        	//+1
            //cout << precede_node->val << " " << follow_node->val << " ";
        	follow_node = precede_node;
        	precede_node = precede_node->next;
        }
        return res;
    }
};
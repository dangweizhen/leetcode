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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        for(int i = 0;i < n-1;i ++)
            cur = cur->next;
        ListNode* removed = head;
        ListNode* removed_last = NULL;

        while(cur->next!=NULL)
        {
            cur = cur->next;
            removed_last = removed;
            removed = removed->next;
        }
        if(removed == head) head = head->next;
        else
        {
            removed_last->next = removed->next;
        }
        delete removed;
        return head;
        
    }
};
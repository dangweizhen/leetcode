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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) return head;
        //return
        ListNode* res = head;
        //probe
        ListNode* l1 = head;
        //first of k
        ListNode* head_n = head;
        //to be swap
        ListNode* precede_n = head;
        ListNode* follow_n = NULL;
        //last of last k
        ListNode* last = NULL;
        ListNode* tmp = head->next;
        bool flag = true;
        while(l1 != NULL)
        {
            /*
            l1, head_n, precede_n: first of k
            follow_n, last: last of last k(if exist)
            tmp: next of first k(if exist)
            */
            //check if remain enough node
            for(int i =0;i < k;i ++)
            {
                if(l1 == NULL) 
                    return res;
                l1 = l1->next;
            }
            //swap
            while(tmp != l1)
            {
                //+1
                follow_n=precede_n;
                precede_n=tmp;
                //swap
                tmp=tmp->next;
                precede_n->next=follow_n;
            }
            if(last != NULL) last->next = precede_n;
            head_n->next=l1;
            //refresh
            if(res == head) res = precede_n;
            if(l1 == NULL || l1->next == NULL) return res;
            tmp = l1->next;
            precede_n = l1;
            follow_n = head_n;
            last = head_n;
            head_n = l1;
        }
        
        return res;
    }
};
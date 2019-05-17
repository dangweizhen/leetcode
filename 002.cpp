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
        int carry = 0;
        ListNode* start1 = l1;
        ListNode* start2 = l2;
        ListNode* last1 = NULL;
        ListNode* last2 = NULL;
        while(l1 != NULL && l2 != NULL)
        {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            l1->val = sum;
            l2->val = sum;
            last1 = l1;
            last2 = l2;
            l1 = l1->next;
            l2 = l2->next; 
        }
        if(l1 != NULL)
        {
            while(l1 != NULL)
            {
                int sum = l1->val + carry;
                carry = sum / 10;
                sum = sum % 10;
                l1->val = sum;
                //if(!carry) break;
                last1 = l1;
                l1 = l1->next;
            }
            if(carry)
            {
                last1->next = new ListNode(carry);
            }
            return start1;
        }
        if(l2 != NULL)
        {
            while(l2 != NULL)
            {
                int sum = l2->val + carry;
                carry = sum / 10;
                sum = sum % 10;
                l2->val = sum;
                last2 = l2;
                l2 = l2->next;
            }
            if(carry)
            {
                last2->next = new ListNode(carry);
            }
            return start2;
        }
        if(carry)
        {
            last1->next = new ListNode(carry);
        }
        return start1;
    }
};
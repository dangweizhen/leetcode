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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 1) return lists[0];
        if(k == 0) return NULL;
        while(k!=1)
        {
            //cout << k << " ";
            for(int i = k%2;i < k;i +=2)
            {
                ListNode* cur_h = NULL;
                ListNode* merge = NULL;
                ListNode* l1 = lists[i];
                ListNode* l2 = lists[i+1];   
                if(l1 == NULL) 
                {
                    lists[(i+1)/2] = l2;
                    continue;
                }
                if(l2 == NULL) 
                {
                    lists[(i+1)/2] = l1;
                    continue;
                }
                if(l1->val > l2->val)
                {
                    merge = l2;
                    cur_h = l2;
                    l2=l2->next;
                }
                else
                {
                    merge = l1;
                    cur_h = l1;
                    l1 = l1->next;
                }
                while(l1!=NULL && l2!=NULL)
                {
                    if(l1->val > l2->val)
                    {
                        merge->next = l2;
                        merge=merge->next;
                        l2=l2->next;
                    }
                    else
                    {
                        merge->next = l1;
                        merge=merge->next;
                        l1 = l1->next;
                    }
                }
                if(l1 == NULL) merge->next=l2;
                else merge->next = l1;
                lists[(i+1)/2] = cur_h;
            }
            k = (k + 1)/2;
        }
        return lists[0];
    }
};
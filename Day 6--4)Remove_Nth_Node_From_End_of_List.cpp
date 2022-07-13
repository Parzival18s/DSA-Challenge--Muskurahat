class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*ptr=head;
        int len=0;
        while(ptr)
        {
            len++;
            ptr=ptr->next;
        }
        len-=n;
        len++;
        if(len==1)
        {
            head=head->next;
        }
        else
        {
            ptr=head;
            for(int i=1;i<len-1;i++)
                ptr=ptr->next;
            ptr->next=ptr->next->next;
        }
        return head;
    }
};

//Link--https://leetcode.com/problems/remove-nth-node-from-end-of-list/
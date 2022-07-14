class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode*ptr,*ans,*head;
        head=new ListNode(0);
        ans=head;
        while(l1 or l2 or carry)
        {
            int tmp=0;
            if(l1)
            {
                tmp+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                tmp+=l2->val;
                l2=l2->next;
            }
            tmp+=carry;
            carry=tmp/10;
            tmp%=10;
            ptr=new ListNode(tmp);
            ans->next=ptr;
            ans=ans->next;
        }
        return head->next;
        
    }
};

//Link--https://leetcode.com/problems/add-two-numbers/
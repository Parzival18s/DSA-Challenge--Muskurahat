class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode* ptr1,*ptr2,*ptr3;
        ptr1=head;
        ptr2=NULL;
        ptr3=ptr1->next;
        while(ptr3)
        {
            ptr1->next=ptr2;
            ptr2=ptr1;
            ptr1=ptr3;
            ptr3=ptr3->next;
            ptr1->next=ptr2;
        }
        return ptr1;
    }
};
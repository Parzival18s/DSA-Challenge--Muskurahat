class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*fast,*slow;
        if(!head)
            return false;
        if(!head->next)
            return false;
        if(head->next==head)
            return true;
        fast=head;
        slow=head;
        fast=fast->next->next;
        while(fast and slow)
        {
            if(fast==slow)
                return true;
            fast=fast->next;
            if(fast)
                fast=fast->next;
            slow=slow->next;
        }
        return false;
    }
};

//Link--https://leetcode.com/problems/linked-list-cycle/
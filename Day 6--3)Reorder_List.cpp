class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode*ptr=head;
        vector<ListNode*>vec;
        while(ptr)
        {
            vec.push_back(ptr);
            ptr=ptr->next;
        }
        int i=0,k=1,j=vec.size()-1;
        while(i<j)
        {
            if(k%2)
            {
                vec[i]->next=vec[j];
                i++;
                k=0;
            }
            else
            {
                vec[j]->next=vec[i];
                j--;
                k=1;
            }
        }
        vec[j]->next=NULL;
    }
};

//Link--https://leetcode.com/problems/reorder-list/
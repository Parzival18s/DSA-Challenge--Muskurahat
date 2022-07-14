class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*>vec;
        int x=0;
        bool change=true;
        while(head)
        {
            vec.push_back(head);
            head=head->next;
            x++;
        }
        x/=k;
        int i=0;
        while(x--)
        {
            int j=i+1;
            while(j<i+k)
            {
                vec[j]->next=vec[j-1];
                j++;
            }
            if(x>0)
            {
                j--;
                j+=k;
                vec[i]->next=vec[j];
            }
            else
            {
                if(j<vec.size())
                    vec[i]->next=vec[j];
                else
                    vec[i]->next=NULL;
            }
            i+=k;
            if(change)
            {
                head=vec[i-1];
                change=false;
            }
        }
        return head;
    }
};

//Link--https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/
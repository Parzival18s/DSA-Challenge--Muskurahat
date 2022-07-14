class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy,*flag,*temp;
        vector<int>vec;
        dummy=new ListNode(0);
        temp=dummy;
        for(int i=0;i<lists.size();i++)
        {
            while(lists[i])
            {
                vec.push_back(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        sort(vec.begin(),vec.end());
        for(auto i:vec)
        {
            flag=new ListNode(i);
            temp->next=flag;
            temp=temp->next;
        }
        return dummy->next;
    }
};

//Link--https://leetcode.com/problems/merge-k-sorted-lists/submissions/
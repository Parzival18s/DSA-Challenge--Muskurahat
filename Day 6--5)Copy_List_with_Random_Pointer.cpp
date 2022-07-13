class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!(head))
            return head;
        unordered_map<Node*,Node*>m;
        Node* start,*p1,*p2,*p3;
        start=new Node(head->val);
        m[head]=start;
        p1=start;
        p2=head->next;
        while(p2)
        {
            p3=new Node(p2->val);
            m[p2]=p3;
            p1->next=p3;
            p1=p1->next;
            p2=p2->next;
        }
        p1=head;
        p2=start;
        while(p1)
        {
            if(p1->random)
                p2->random=m[p1->random];
            p1=p1->next;
            p2=p2->next;
        }
        return start;
    }
};

//Link--https://leetcode.com/problems/copy-list-with-random-pointer/
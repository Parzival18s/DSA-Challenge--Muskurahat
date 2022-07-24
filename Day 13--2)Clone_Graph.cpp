class Solution {
public:
    unordered_map<Node*,Node*>m;
    void helper1(Node* node)
    {
        Node* ptr;
        ptr=new Node(node->val);
        m[node]=ptr;
        for(int i=0;i<node->neighbors.size();i++)
        {
            if(m.find(node->neighbors[i])==m.end())
                helper1(node->neighbors[i]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        helper1(node);
        for(auto &i:m)
        {
            for(int j=0;j<i.first->neighbors.size();j++)
                i.second->neighbors.push_back(m[i.first->neighbors[j]]);
        }
        return m[node];
    }
};

//Link--https://leetcode.com/problems/clone-graph/
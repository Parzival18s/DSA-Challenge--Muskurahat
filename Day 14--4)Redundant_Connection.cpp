class Solution {
public:
    unordered_map<int,int>m;
    int helper(int i)
    {
        if(m[i]==i)
            return i;
        return m[i]=helper(m[i]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i=1;i<=edges.size();i++)
            m[i]=i;
        vector<int>ans;
        for(int i=0;i<edges.size();i++)
        {
            int a=helper(edges[i][0]);
            int b=helper(edges[i][1]);
            if(a==b)
            {
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
                break;
            }
            m[b]=a;
        }
        return ans;
    }
};

//Link--https://leetcode.com/problems/redundant-connection/
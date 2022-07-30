class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v;
        v.push_back(0);
        if(n==0)
            return v;
        v.push_back(1);
        for(int i=2;i<=n;i++)
        {
            if(i%2)
                v.push_back(v[v.size()-1]+1);
            else
                v.push_back(v[i/2]);
        }
        return v;
    }
};

//Link--https://leetcode.com/problems/counting-bits/
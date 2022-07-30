class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int ans=0;
        vector<int>v(32,0);
        int i=0;
        while(n>0)
        {
            v[i]=n%2;
            i++;
            n/=2;
        }
        reverse(v.begin(),v.end());
        for(i=0;i<=31;i++)
        {
            if(v[i]==1)
                ans+=pow(2,i);
        }
        return ans;
    }
};

//Link--https://leetcode.com/problems/reverse-bits/
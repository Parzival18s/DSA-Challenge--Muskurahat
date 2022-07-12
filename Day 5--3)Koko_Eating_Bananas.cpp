class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mn=1,mx=-1;
        for(int i=0;i<piles.size();i++)
            mx=max(mx,piles[i]);
        while(mx>mn)
        {
            int mid=(mx+mn)/2;
            int tmp=0;
            for(int i=0;i<piles.size();i++)
            {
                tmp+=(piles[i]/mid);
                if(piles[i]%mid!=0)
                    tmp++;
            }
            if(tmp<=h)
                mx=mid;
            else
                mn=mid+1;
        }
        return mx;
    }
};

//Link--https://leetcode.com/problems/koko-eating-bananas/
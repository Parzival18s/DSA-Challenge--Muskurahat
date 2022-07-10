class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,bp=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(bp<prices[i])
                ans=max(ans,prices[i]-bp);
            else
                bp=prices[i];
        }
        return ans;
    }
};

//Link--https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN,cnt=0,tmp;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
                cnt++;
            ans=max(ans,nums[i]);
        }
        if(cnt==0)
            return ans;
        tmp=0;
        for(int i=0;i<nums.size();i++)
        {
            tmp+=nums[i];
            if(tmp<0)
                tmp=0;
            ans=max(ans,tmp);
        }
        return ans;
        
    }
};

//Link--https://leetcode.com/problems/maximum-subarray/
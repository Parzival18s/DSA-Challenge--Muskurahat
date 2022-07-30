class Solution {
public:
    int arr[102];
    set<pair<int,bool>>s;
    int helper(vector<int>nums,int in,bool parent)
    {
        if(in<0)
            return 0;
        if(in==0)
        {
            if(parent)
                return 0;
            return nums[0];
        }
        if(s.count({in,parent}))
            return arr[in];
        s.insert({in,parent});
        if(parent)
            return helper(nums,in-1,false);
        int t1,t2;
        t1=helper(nums,in-1,false);
        t2=nums[in]+helper(nums,in-1,true);
        return arr[in]=max(t1,t2);
    }
    int rob(vector<int>& nums) {
        memset(arr,-1,sizeof(arr));
        return helper(nums,nums.size()-1,false);
    }
};

//Link--https://leetcode.com/problems/house-robber/
class Solution {
public:
    int arr[102];
    set<pair<int,bool>>s;
    int helper(vector<int>nums,int in,bool parent,bool root)
    {
        if(in<0)
            return 0;
        if(in==0)
        {
            if(parent or root)
                return 0;
            return nums[0];
        }
        if(s.count({in,parent}))
            return arr[in];
        s.insert({in,parent});
        if(parent)
            return helper(nums,in-1,false,root);
        int t1,t2;
        t1=helper(nums,in-1,false,root);
        t2=nums[in]+helper(nums,in-1,true,root);
        return arr[in]=max(t1,t2);
    }
    int rob(vector<int>& nums) {
        memset(arr,-1,sizeof(arr));
        int x,y;
        x=helper(nums,nums.size()-2,false,false);
        memset(arr,-1,sizeof(arr));
        s.clear();
        y=nums[nums.size()-1]+helper(nums,nums.size()-2,true,true);
        return max(x,y);
    }
};

//Link--https://leetcode.com/problems/house-robber-ii/
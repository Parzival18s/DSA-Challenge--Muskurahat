class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>nums,int in,vector<int>v,int target)
    {
        if(in==nums.size())
            return;
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        if(target>=nums[in])
        {
            helper(nums,in+1,v,target);
            target-=nums[in];
            v.push_back(nums[in]);
            helper(nums,in,v,target);
            return;
        }
        helper(nums,in+1,v,target);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        helper(candidates,0,v,target);
        return ans;
    }
};

//Link--https://leetcode.com/problems/combination-sum/
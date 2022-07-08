class Solution {
public:
    unordered_set<int>s;
    unordered_map<int,int>m;
    unordered_map<int,int>dp;
    int helper(int a)
    {
        if(!s.count(a))
            return 0;
        if(dp[a]!=-1)
            return dp[a];
        int t1=1;
        int t2=helper(a-1);
        return dp[a]=t1+t2;
    }
    int longestConsecutive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
            m[nums[i]]++;
            dp[nums[i]]=-1;
        }
        int ans=0;
        for(auto &i:m)
        {
            ans=max(ans,helper(i.first));
        }
        return ans;
    }
};

//Question Link--https://leetcode.com/problems/longest-consecutive-sequence/
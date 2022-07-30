class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++)
            ans^=nums[i];
        if(n%4==0)
            ans^=n;
        else if(n%4==1)
            ans^=1;
        else if(n%4==2)
            ans^=(n+1);
        return ans;
    }
};

//Link--https://leetcode.com/problems/missing-number/
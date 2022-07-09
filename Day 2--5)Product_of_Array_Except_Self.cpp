class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int tmp=1,n=nums.size();
        vector<int>ans(n),prefix,suffix;
        for(int i=0;i<n;i++)
        {
            tmp*=nums[i];
            prefix.push_back(tmp);
        }
        tmp=1;
        for(int i=n-1;i>=0;i--)
        {
            tmp*=nums[i];
            suffix.push_back(tmp);
        }
        reverse(suffix.begin(),suffix.end());
        ans[0]=suffix[1];
        ans[n-1]=prefix[n-2];
        for(int i=1;i<n-1;i++)
            ans[i]=prefix[i-1]*suffix[i+1];
        return ans;
    }
};

//Link--https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    int helper(vector<int>nums,int i,int j,int target)
    {
        int mid;
        while(i<=j)
        {
            mid=(i+j)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                j=mid-1;
            else
                i=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        if(nums[i]<=nums[j])
            return helper(nums,i,j,target);
        int pivot=-1,mid;
        while(pivot==-1)
        {
            mid=(i+j)/2;
            if(nums[mid]>nums[mid+1])
                pivot=mid+1;
            else if(nums[i]<nums[mid])
                i=mid;
            else
                j=mid;
        }
        if(target>=nums[0])
            return helper(nums,0,pivot-1,target);
        return helper(nums,pivot,nums.size()-1,target);
        
    }
};

//Link--https://leetcode.com/problems/search-in-rotated-sorted-array/
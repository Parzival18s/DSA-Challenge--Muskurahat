class Solution {
public:
    int findMin(vector<int>& nums) {
        int pivot=-1,i=0,j=nums.size()-1;
        if(nums[i]<=nums[j])
            return nums[i];
        while(pivot==-1)
        {
            int mid=(i+j)/2;
            if(nums[mid]>nums[mid+1])
                pivot=mid+1;
            else if(nums[i]<nums[mid])
                i=mid;
            else
                j=mid;
        }
        return nums[pivot];
    }
};

//Link--https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
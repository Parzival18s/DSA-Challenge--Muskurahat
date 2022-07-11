class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>check;
        int i=0,j=0;
        while(j<nums.size())
        {
            while(!check.empty() and nums[j]>check.back())
                check.pop_back();
            check.push_back(nums[j]);
            if(j-i+1==k)
            {
                ans.push_back(check.front());
                if(check.front()==nums[i])
                    check.pop_front();
                i++;
            }
            j++;
        }
        return ans;
    }
};

//Link--https://leetcode.com/problems/sliding-window-maximum/

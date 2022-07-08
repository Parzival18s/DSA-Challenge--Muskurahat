class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        unordered_set<int>s;
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=target-nums[i])
            {
                s.insert(nums[i]);
                m[nums[i]]=i;
                if(s.count(target-nums[i]))
                {
                    v.push_back(m[nums[i]]);
                    v.push_back(m[target-nums[i]]);
                    break;
                }
            }
            else
            {
                if(s.count(nums[i]))
                {
                    v.push_back(i);
                    v.push_back(m[nums[i]]);
                    break;
                }
                else
                {
                    s.insert(nums[i]);
                    m[nums[i]]=i;
                    
                }
            }
        }
        return v;
    }
};

//Question Link--https://leetcode.com/problems/two-sum/
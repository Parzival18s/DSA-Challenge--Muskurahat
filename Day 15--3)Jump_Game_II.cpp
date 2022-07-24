class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        queue<int>q;
        int ans=0,str=1;
        q.push(0+nums[0]);
        while(1)
        {
            int x=q.size();
            int tmp=0;
            while(x--)
            {
                tmp=max(tmp,q.front());
                q.pop();
            }
            ans++;
            if(tmp>=nums.size()-1)
                break;
            while(str<=tmp)
            {
                q.push(str+nums[str]);
                str++;
            }
        }
        return ans;
    }
};

//Link--https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size(),0);
        stack<int>s;
        for(int i=temperatures.size()-1;i>=0;i--)
        {
            while(!s.empty() and temperatures[i]>=temperatures[s.top()])
                s.pop();
            if(!s.empty())
                ans[i]=s.top()-i;
            s.push(i);
        }
        return ans;
    }
};

//Link--https://leetcode.com/problems/daily-temperatures/
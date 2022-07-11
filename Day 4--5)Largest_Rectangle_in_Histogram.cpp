class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nll(heights.size(),-1),nlr(heights.size(),heights.size());
        stack<int>s;
        int ans=0;
        for(int i=0;i<heights.size();i++)
        {
            while(!s.empty() and heights[i]<=heights[s.top()])
                s.pop();
            if(!s.empty())
                nll[i]=s.top();
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(!s.empty() and heights[i]<=heights[s.top()])
                s.pop();
            if(!s.empty())
                nlr[i]=s.top();
            s.push(i);
        }
        for(int i=0;i<heights.size();i++)
            ans=max(ans,heights[i]*(nlr[i]-nll[i]-1));
        return ans;
    }
};

//Link--https://leetcode.com/problems/largest-rectangle-in-histogram/
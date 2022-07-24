class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size()-1;i++)
        {
            if(intervals[i][1]>=intervals[i+1][0])
            {
                intervals[i+1][0]=intervals[i][1];
                intervals[i+1][1]=max(intervals[i][1],intervals[i+1][1]);
            }
        }
        for(int i=0;i<intervals.size();i++)
        {
            if(i==intervals.size()-1)
                ans.push_back(intervals[i]);
            else if(intervals[i][1]!=intervals[i+1][0])
                ans.push_back(intervals[i]);
            else
            {
                int a,b;
                a=intervals[i][0];
                while(i<intervals.size()-1 and intervals[i][1]==intervals[i+1][0])
                    i++;
                b=intervals[i][1];
                ans.push_back({a,b});
            }
        }
        return ans;
    }
};

//Link--https://leetcode.com/problems/merge-intervals/
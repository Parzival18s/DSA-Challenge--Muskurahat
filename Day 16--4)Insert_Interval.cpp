class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        if(intervals.size()==0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        if(newInterval[1]<intervals[0][0])
        {
            ans.push_back(newInterval);
            for(int i=0;i<intervals.size();i++)
                ans.push_back(intervals[i]);
            return ans;
        }
        else if(newInterval[1]==intervals[0][0])
        {
            intervals[0][0]=newInterval[0];
            return intervals;
        }
        if(intervals.size()==1)
        {
            if(intervals[0][1]<newInterval[0])
            {
                intervals.push_back(newInterval);
                return intervals;
            }
            intervals[0][0]=min(intervals[0][0],newInterval[0]);
            intervals[0][1]=max(intervals[0][1],newInterval[1]);
            return intervals;
        }
        int i=0,j;
        while(i<intervals.size() and intervals[i][1]<newInterval[0])
            i++;
        if(i==intervals.size())
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        if(intervals[i][0]<=newInterval[1])
        {
            intervals[i][0]=min(intervals[i][0],newInterval[0]);
            j=i;
            while(j<intervals.size() and intervals[j][0]<=newInterval[1])
                j++;
            for(int p=0;p<i;p++)
                ans.push_back(intervals[p]);
            ans.push_back({intervals[i][0],max(intervals[j-1][1],newInterval[1])});
            for(int p=j;p<intervals.size();p++)
                ans.push_back(intervals[p]);
        }
        else
        {
            for(int p=0;p<i;p++)
                ans.push_back(intervals[p]);
            ans.push_back(newInterval);
            for(int p=i;p<intervals.size();p++)
                ans.push_back(intervals[p]);
        }
        return ans;
    }
};

//Link--https://leetcode.com/problems/insert-interval/
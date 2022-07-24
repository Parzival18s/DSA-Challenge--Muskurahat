class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        int a,b,tmp;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<points.size();i++)
        {
            a=points[i][0];
            b=points[i][1];
            tmp=(a*a)+(b*b);
            pq.push({tmp,{a,b}});
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty())
        {
            a=pq.top().second.first;
            b=pq.top().second.second;
            ans.push_back({a,b});
            pq.pop();
        }
        return ans;
    }
};

//Link--https://leetcode.com/problems/k-closest-points-to-origin/
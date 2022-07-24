class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses,false);
        vector<int>adj[numCourses];
        vector<int>ans;
        for(int i=0;i<prerequisites.size();i++)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        while(1)
        {
            int x=0;
            for(int i=0;i<vis.size();i++)
            {
                if(!vis[i])
                {
                    bool status=true;
                    for(int j=0;j<adj[i].size();j++)
                    {
                        if(!vis[adj[i][j]])
                        {
                            status=false;
                            break;
                        }
                    }
                    if(status)
                    {
                        vis[i]=true;
                        ans.push_back(i);
                        x=1;
                    }
                }
            }
            if(x==0)
                break;
        }
        if(ans.size()==numCourses)
            return ans;
        vector<int>t;
        return t;
    }
};

//Link--https://leetcode.com/problems/course-schedule-ii/
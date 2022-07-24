class Solution {
public:
    bool helper(vector<int>adj[],vector<int>&vis,int id)
    {
        if(vis[id]==1)
            return true;
        if(vis[id]==0)
        {
            vis[id]=1;
            for(auto edge:adj[id])
            {
                if(helper(adj,vis,edge))
                    return true;
            }
        }
        vis[id]=2;
        return false;
    }
    bool canFinish(int numCourses,vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        vector<int>vis(numCourses,0);
        for(int i=0;i<vis.size();i++)
        {
            if(helper(adj,vis,i))
                return false;
        }
        return true;
    }
};

//Link--https://leetcode.com/problems/course-schedule/
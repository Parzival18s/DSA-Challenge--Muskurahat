class Solution {
public:
    bool pacific(vector<vector<int>>&heights,int i,int j,vector<vector<int>>&pac)
    {
        if(i==0 or j==0)
            return true;
        if(i==heights.size() or j==heights[0].size())
            return false;
        if(pac[i][j]!=-1)
        {
            if(pac[i][j]==1)
                return true;
            return false;
        }
        int x=heights[i][j];
        heights[i][j]=INT_MAX;
        bool a=false,b=false,c=false,d=false;
        if(heights[i-1][j]<=x)
            a=pacific(heights,i-1,j,pac);
        if(!a)
        {
            if((i+1)<heights.size() and heights[i+1][j]<=x)
                b=pacific(heights,i+1,j,pac);
        }
        if(!a and !b)
        {
            if(heights[i][j-1]<=x)
                c=pacific(heights,i,j-1,pac);
        }
        if(!a and !b and !c)
        {
            if((j+1)<heights[0].size() and heights[i][j+1]<=x)
                d=pacific(heights,i,j+1,pac);
        }
        heights[i][j]=x;
        return a or b or c or d;
    }
    bool atlantic(vector<vector<int>>&heights,int i,int j,vector<vector<int>>&atl)
    {
        if(i<0 or j<0)
            return false;
        if(i==heights.size()-1 or j==heights[0].size()-1)
            return true;
        if(atl[i][j]!=-1)
        {
            if(atl[i][j]==1)
                return true;
            return false;
        }
        int x=heights[i][j];
        heights[i][j]=INT_MAX;
        bool a=false,b=false,c=false,d=false;
        if((i-1)>=0 and heights[i-1][j]<=x)
            a=atlantic(heights,i-1,j,atl);
        if(!a)
        {
            if(heights[i+1][j]<=x)
                b=atlantic(heights,i+1,j,atl);
        }
        if(!a and !b)
        {
            if((j-1)>=0 and heights[i][j-1]<=x)
                c=atlantic(heights,i,j-1,atl);
        }
        if(!a and !b and !c)
        {
            if(heights[i][j+1]<=x)
                d=atlantic(heights,i,j+1,atl);
        }
        heights[i][j]=x;
        return a or b or c or d;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        vector<vector<int>>pac(heights.size(),vector<int>(heights[0].size(),-1));
        vector<vector<int>>atl(heights.size(),vector<int>(heights[0].size(),-1));
        for(int i=0;i<heights.size();i++)
        {
            for(int j=0;j<heights[0].size();j++)
            {
                if(pacific(heights,i,j,pac))
                    pac[i][j]=1;
                else
                    pac[i][j]=0;
                if(atlantic(heights,i,j,atl))
                    atl[i][j]=1;
                else
                    atl[i][j]=0;
                if(pac[i][j]==1 and atl[i][j]==1)
                {
                    vector<int>v;
                    v.push_back(i);
                    v.push_back(j);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};

//Link--https://leetcode.com/problems/pacific-atlantic-water-flow/
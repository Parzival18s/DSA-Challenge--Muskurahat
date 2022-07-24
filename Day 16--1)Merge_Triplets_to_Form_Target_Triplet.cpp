class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a=false,b=false,c=false;
        int x,y,z;
        x=target[0];
        y=target[1];
        z=target[2];
        for(int i=0;i<triplets.size();i++)
        {
            if(triplets[i][0]==x and triplets[i][1]<=y and triplets[i][2]<=z)
                a=true;
            if(triplets[i][1]==y and triplets[i][0]<=x and triplets[i][2]<=z)
                b=true;
            if(triplets[i][2]==z and triplets[i][0]<=x and triplets[i][1]<=y)
                c=true;
        }
        return a and b and c;
    }
};

//Link--https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
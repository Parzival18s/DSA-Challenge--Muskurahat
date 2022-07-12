class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j=0;
        while(i<matrix.size() and j<matrix[0].size())
        {
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]>target)
                return false;
            else if(i+1<matrix.size() and matrix[i+1][j]<=target)
                i++;
            else
                j++;
        }
        return false;
    }
};

//Link--https://leetcode.com/problems/search-a-2d-matrix/
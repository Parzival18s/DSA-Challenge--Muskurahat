class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>v;
        int m=matrix.size(),n=matrix[0].size();
        int i=0,j=0,dir=0;
        while(v.size()!=m*n)
        {
            if((dir%4)==0)
            {
                while((j<n-1) and (matrix[i][j+1]!=101))
                {
                    v.push_back(matrix[i][j]);
                    matrix[i][j]=101;
                    j++;
                }
                v.push_back(matrix[i][j]);
                matrix[i][j]=101;
                i++;
                dir=1;
            }
            else if((dir%4)==1)
            {
                while((i<m-1) and (matrix[i+1][j]!=101))
                {
                    v.push_back(matrix[i][j]);
                    matrix[i][j]=101;
                    i++;
                }
                v.push_back(matrix[i][j]);
                matrix[i][j]=101;
                j--;
                dir=2;
            }
            else if((dir%4)==2)
            {
                while((j>0) and (matrix[i][j-1]!=101))
                {
                    v.push_back(matrix[i][j]);
                    matrix[i][j]=101;
                    j--;
                }
                v.push_back(matrix[i][j]);
                matrix[i][j]=101;
                i--;
                dir=3;
            }
            else
            {
                while((i>0) and (matrix[i-1][j]!=101))
                {
                    v.push_back(matrix[i][j]);
                    matrix[i][j]=101;
                    i--;
                }
                v.push_back(matrix[i][j]);
                matrix[i][j]=101;
                j++;
                dir=0;
            }
        }
        return v;
    }
};

//Link--https://leetcode.com/problems/spiral-matrix/
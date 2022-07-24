class Solution {
public:
    void helper(vector<vector<char>>&board,int i,int j)
    {
        if(i<0 or j<0 or i==board.size() or j==board[0].size() or board[i][j]!='O')
            return;
        board[i][j]='Y';
        helper(board,i+1,j);
        helper(board,i-1,j);
        helper(board,i,j+1);
        helper(board,i,j-1);
        return;
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O')
                helper(board,0,i);
            if(board[m-1][i]=='O')
                helper(board,m-1,i);
        }
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
                helper(board,i,0);
            if(board[i][n-1]=='O')
                helper(board,i,n-1);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='Y')
                    board[i][j]='O';
                else
                    board[i][j]='X';
            }
        }
    }
};

//Link--https://leetcode.com/problems/surrounded-regions/
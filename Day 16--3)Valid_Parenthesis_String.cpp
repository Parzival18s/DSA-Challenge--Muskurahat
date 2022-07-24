class Solution {
public:
    bool checkValidString(string s) {
        int left=0,right=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')')
                right++;
            else
                left++;
            if(right>left)
                return false;
        }
        left=0;
        right=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='(')
                left++;
            else
                right++;
            if(left>right)
                return false;
        }
        return true;
    }
};

//Link--https://leetcode.com/problems/valid-parenthesis-string/
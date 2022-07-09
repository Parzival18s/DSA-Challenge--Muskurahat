class Solution {
public:
    string convert(string s)
    {
        string ret="";
        for(int i=0;i<s.length();i++)
        {
            if(((s[i]>='0' && (s[i]<='9'))) || ((s[i]>='a' && (s[i]<='z'))))
                ret+=s[i];
            else if(((s[i]>='A') && (s[i]<='Z')))
                ret+=char(int(s[i])+32);
            else
                continue;
        }
        return ret;
    }
    bool isPalindrome(string s) {
        string help;
        help=convert(s);
        int st=0,e=help.size()-1;
        while(st<=e)
        {
            if(help[st]==help[e])
            {
                st++;
                e--;
            }
            else
                return false;
        }
        return true;
    }
};

//Link--https://leetcode.com/problems/valid-palindrome/
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char,int>prec;
        prec['(']=1;
        prec[')']=1;
        prec['{']=2;
        prec['}']=2;
        prec['[']=3;
        prec[']']=3;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' or s[i]=='[' or s[i]=='{')
                st.push(s[i]);
            else
            {
                if(st.empty() or prec[s[i]]!=prec[st.top()])
                    return false;
                else
                    st.pop();
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};

//Link--https://leetcode.com/problems/valid-parentheses/
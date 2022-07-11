class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+")
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                b+=a;
                s.push(b);
            }
            else if(tokens[i]=="-")
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                b-=a;
                s.push(b);
            }
            else if(tokens[i]=="*")
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                b*=a;
                s.push(b);
            }
            else if(tokens[i]=="/")
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                b/=a;
                s.push(b);
            }
            else
                s.push(stoi(tokens[i])); 
        }
        return s.top();
    }
};

//Link--https://leetcode.com/problems/evaluate-reverse-polish-notation/
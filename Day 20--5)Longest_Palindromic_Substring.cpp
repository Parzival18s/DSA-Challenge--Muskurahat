class Solution {
public:
    string longestPalindrome(string s) {
    int ans=1,temp,j;
    string a,p="",q="";
    for(int i=0;i<s.length();i++)
    {
        if( (i<s.size()-2) && (s[i]==s[i+2]))
        {
            p+=s[i+1];
            p+=s[i];
            q+=s[i+2];
            temp=3;
            j=1;
            while((i-j>=0) && ((i+2+j)<s.size()) && (s[i-j]==s[i+2+j]))
            {
                p+=s[i-j];
                q+=s[i+j+2];
                temp+=2;
                j++;
            }
            if(temp>ans)
            {
                ans=temp;
                reverse(p.begin(),p.end());
                a=p+q;
            }
            p="";
            q="";
        }
        if( (i<s.size()-1) && (s[i]==s[i+1]))
        {
            p+=s[i];
            q+=s[i+1];
            temp=2;
            j=1;
            while((i-j>=0) && ((i+1+j)<s.size()) && (s[i-j]==s[i+1+j]) )
            {
                p+=s[i-j];
                q+=s[i+1+j];
                temp+=2;
                j++;
            }
            if(temp>ans)
            {
                ans=temp;
                reverse(p.begin(),p.end());
                a=p+q;
            }
            p="";
            q="";
        }
    }
    if(ans==1)
        a=s[0];
    return a;
    }
};
class Solution {
public:
    unordered_map<int,string>m;
    vector<string>vec;
    int len;
    
    void indexer(string s,int in)
    {
        string st="";
        int c=0,tmp;
        for(int i=s.size()-1;i>=0;i--)
        {
            tmp=in*(s[i]-'0');
            tmp+=c;
            c=tmp/10;
            tmp%=10;
            st+=to_string(tmp);
        }
        if(c)
            st+=to_string(c);
        reverse(st.begin(),st.end());
        m[in]=st;
    }
    
    void multiplier(int in,int tens)
    {
        string tmp;
        tmp=m[in];
        for(int i=0;i<tens;i++)
            tmp+="0";
        reverse(tmp.begin(),tmp.end());
        while(tmp.size()<len)
            tmp+="0";
        reverse(tmp.begin(),tmp.end());
        vec.push_back(tmp);
    }
    
    string adder()
    {
        string ans="";
        int c=0,tmp=0;
        for(int i=len-1;i>=0;i--)
        {
            for(int j=0;j<vec.size();j++)
                tmp+=vec[j][i]-'0';
            tmp+=c;
            c=tmp/10;
            tmp%=10;
            ans+=to_string(tmp);
            tmp=0;
        }
        if(c)
            ans+=to_string(c);
        reverse(ans.begin(),ans.end());
        int i=0;
        while(ans[i]=='0')
            i++;
        if(i==ans.size())
            return "0";
        return ans.substr(i,ans.size()-i+1);
    }
    
    string multiply(string num1, string num2) {
        
        for(int i=0;i<=9;i++)
            indexer(num1,i);
        int k=0;
        len=num1.size()+num2.size();
        for(int i=num2.size()-1;i>=0;i--)
        {
            multiplier(num2[i]-'0',k);
            k++;
        }
        return adder();
    }
};

//Link--https://leetcode.com/problems/multiply-strings/
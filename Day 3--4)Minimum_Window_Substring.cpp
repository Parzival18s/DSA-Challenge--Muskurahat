class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        for(int i=0;i<t.size();i++)
            m[t[i]]++;
        vector<char>vec;
        vector<int>ind;
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]]>0)
            {
                vec.push_back(s[i]);
                ind.push_back(i);
            }
        }
        int i=0,j=0,ans=INT_MAX,cnt=t.size();
        string str;
        while(j<vec.size())
        {
            if(m[vec[j]]>0)
            {
                cnt--;
                m[vec[j]]--;
            }
            else
                m[vec[j]]--;
            if(cnt==0)
            {
                while(m[vec[i]]<0)
                {
                    m[vec[i]]++;
                    i++;
                }
                if(ans>(ind[j]-ind[i]+1))
                {
                    ans=ind[j]-ind[i]+1;
                    str=s.substr(ind[i],ans);
                }
            }
            j++;
        }
        return str;
    }
};

//Link--https://leetcode.com/problems/minimum-window-substring/
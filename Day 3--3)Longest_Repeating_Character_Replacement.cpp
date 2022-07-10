class Solution {
public:
    unordered_map<char,int>m;
    int helper()
    {
        int tmp=0;
        for(auto &i:m)
            tmp=max(tmp,i.second);
        return tmp;
    }
    int characterReplacement(string s, int k) {
        int i=0,j=0;
        int cnt=0,tot=0,ans=0;
        while(j<s.size())
        {
            if(m[s[j]]==cnt)
            {
                m[s[j]]++;
                cnt++;
                tot++;
            }
            else
            {
                m[s[j]]++;
                tot++;
            }
            while(tot-cnt>k)
            {
                if(m[s[i]]==cnt)
                {
                    m[s[i]]--;
                    tot--;
                    cnt=helper();
                    i++;
                }
                else
                {
                    m[s[i]]--;
                    tot--;
                    i++;
                }
            }
            ans=max(ans,tot);
            j++;
        }
        return ans;
    }
};

//Link--https://leetcode.com/problems/longest-repeating-character-replacement/
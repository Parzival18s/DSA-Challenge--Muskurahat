class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,ans=0;
        unordered_map<int,int>m;
        while(j<s.size())
        {
            m[s[j]]++;
            while(m[s[j]]>1)
            {
                m[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};

//Link--https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
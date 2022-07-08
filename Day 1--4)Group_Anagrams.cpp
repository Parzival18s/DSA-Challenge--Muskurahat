class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        vector<vector<string>>v;
        string tmp;
        for(int i=0;i<strs.size();i++)
        {
            tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            m[tmp].push_back(strs[i]);
        }
        for(auto &i:m)
            v.push_back(i.second);
        return v;
    }
};

//Question Link--https://leetcode.com/problems/group-anagrams/
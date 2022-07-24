class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())
            return 0;
        unordered_set<string> s;
        for(int i=0;i<wordList.size();i++)
            s.insert(wordList[i]);
        queue<string> q;
        q.push(beginWord);
        int d=0;
        while(!q.empty())
        {
            d++;
            int n=q.size();
            while(n--)
            {
                string tmp=q.front();
                q.pop();
                for(int i=0;i<tmp.length();i++)
                {
                    string str=tmp;
                    for(char c='a';c<='z';c++)
                    {
                        str[i]=c;
                        if(str==tmp)
                            continue;
                        if(str==endWord)
                            return d+1;
                        if(s.find(str)!=s.end())
                        {
                            q.push(str);
                            s.erase(str);
                        }
                    }
                }
            }
        }
        return 0;
    }
};

//Link--https://leetcode.com/problems/word-ladder/
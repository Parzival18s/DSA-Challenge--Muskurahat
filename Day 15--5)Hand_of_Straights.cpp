class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<long long,long long>v;
        for(long long i=0;i<hand.size();i++)
            v[hand[i]]++;
        int c=hand.size(),start=0;
        while(c>0)
        {
            if(v[start]>0)
            {
                int end=start+groupSize;
                for(int i=start+1;i<end;i++)
                {
                    if(v[i]>=v[start])
                    {
                        v[i]-=v[start];
                        c-=v[start];
                    }
                    else
                        return false;
                }
                c-=v[start];
                v[start]=0;
            }
            for(auto &i:v)
            {
                if(i.second>0)
                {
                    start=i.first;
                    break;
                }
            }
        }
        return true;
    }
};

//Link--https://leetcode.com/problems/hand-of-straights/
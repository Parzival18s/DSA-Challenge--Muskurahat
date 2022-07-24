class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int a,b;
        for(int i=0;i<stones.size();i++)
            pq.push(stones[i]);
        while(pq.size()>1)
        {
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            a-=b;
            if(a!=0)
                pq.push(a);
        }
        if(pq.empty())
            return 0;
        return pq.top();
    }
};

//Link--https://leetcode.com/problems/last-stone-weight/
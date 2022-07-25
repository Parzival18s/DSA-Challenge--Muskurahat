class Solution {
public:
    bool isHappy(int n) {
        if(n==1)
            return true;
        unordered_set<int>s;
        s.insert(n);
        int x,tmp=0;
        bool flag=false;
        while(1)
        {
            while(n>0)
            {
                x=n%10;
                n/=10;
                x*=x;
                tmp+=x;
            }
            if(s.count(tmp))
                break;
            s.insert(tmp);
            if(tmp==1)
            {
                flag=true;
                break;
            }
            n=tmp;
            tmp=0;
        }
        return flag;
    }
};

//Link--https://leetcode.com/problems/happy-number/
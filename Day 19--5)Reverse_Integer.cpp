class Solution {
public:
    int reverse(int x) {
        int ans=0,tmp,sign=1;
        if(x<0)
        {
            if(x==-1*pow(2,31))
                return 0;
            x*=-1;
            sign=-1;
        }
        while(x>0)
        {
            tmp=x%10;
            if(ans<INT_MAX/10 or (ans==INT_MAX/10 and tmp<=INT_MAX%10))
            {
                ans*=10;
                ans+=tmp;
                x/=10;
            }
            else
            {
                ans=0;
                break;
            }
        }
        return ans*sign;
    }
};

//Link--https://leetcode.com/problems/reverse-integer/
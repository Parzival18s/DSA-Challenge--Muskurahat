class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        if(x==0)
            return 0;
        if(n<0)
            return 1/x*myPow(1/x ,-(n + 1));
        if(n%2)
            return x*myPow(x*x,n/2);
        return myPow(x*x,n/2);
    }
};

//Link--https://leetcode.com/problems/powx-n/submissions/
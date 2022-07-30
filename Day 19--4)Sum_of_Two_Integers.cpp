class Solution {
public:
    void helper(vector<int>&v)
    {
        for(int i=0;i<12;i++)
        {
            if(v[i]==1)
                v[i]=0;
            else
                v[i]=1;
        }
        int c=1,j=0;
        while(j<12 and c==1)
        {
            if(v[j]==0)
            {
                v[j]=1;
                c=0;
            }
            else
            {
                v[j]=0;
                c=1;
            }
            j++;
        }
        return;
    }
    int getSum(int a, int b) {
        vector<int>p(12,0),q(12,0);
        int c=0,i=0,fa=0,fb=0,fc=0;
        if(a<0)
        {
            a*=-1;
            fa=1;
        }
        if(b<0)
        {
            b*=-1;
            fb=1;
        }
        if(fa==1 and fb==0)
        {
            if(a>b)
                fc=1;
        }
        if(fa==0 and fb==1)
        {
            if(b>a)
                fc=1;
        }
        if(fa==1 and fb==1)
            fc=1;
        while(a>0)
        {
            p[i]=a%2;
            i++;
            a/=2;
        }
        i=0;
        while(b>0)
        {
            q[i]=b%2;
            i++;
            b/=2;
        }
        if(fa==1)
            helper(p);
        if(fb==1)
            helper(q);
        for(i=0;i<12;i++)
        {
            int none=0;
            if(p[i]==1)
                none++;
            if(q[i]==1)
                none++;
            if(c==1)
                none++;
            if(none==0)
            {
                p[i]=0;
                c=0;
            }
            else if(none==1)
            {
                p[i]=1;
                c=0;
            }
            else if(none==2)
            {
                p[i]=0;
                c=1;
            }
            else
            {
                p[i]=1;
                c=1;
            }
        }
        if(fc==1)
            helper(p);
        c=0;
        for(i=0;i<12;i++)
        {
            if(p[i]==1)
                c+=pow(2,i);
        }
        if(fc==1)
            c*=-1;
        return c;
    }
};

//Link--https://leetcode.com/problems/sum-of-two-integers/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        map<vector<int>,int> m;
        int n=a.size();
        vector<vector<int>> res;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            int l=0,r=n-1;
            while(l<i && r>i)
            {
                if(a[l]+a[r]+a[i]==0)
                {
                    m[{a[l],a[i],a[r]}]=1;
                    l++;
                    r--;
                }
                else if(a[l]+a[r]+a[i]>0)
                    r--;
                else
                    l++;
            }
        }
        for(auto &c:m)
            res.push_back(c.first);
        return res;
    }
};

//Link--https://leetcode.com/problems/3sum/
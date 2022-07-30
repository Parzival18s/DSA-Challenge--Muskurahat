class DetectSquares {
public:
    vector<unordered_map<int,int>>vec;
    
    DetectSquares() {
        vec=vector<unordered_map<int,int>>(1001);
    }
    
    void add(vector<int> point) {
        int x=point[0];
        int y=point[1];
        vec[x][y]++;
    }
    
    int count(vector<int> point) {
        int x=point[0],y=point[1];
        int ans=0;
        for (auto& it:vec[x])
        {
            int p=it.first;
            int cnt=it.second;
            
            if (y==p)
                continue;
            int len=abs(p-y);
            
            if (x+len<=1000)
            {
                int q=x+len;
                ans+=vec[x][p]*vec[q][p]*vec[q][y];
            }
			
            if(x-len>=0)
            {
                int q=x-len;
                ans+=vec[x][p]*vec[q][p]*vec[q][y];
            }
        }
        return ans;
    }
};

//Link--https://leetcode.com/problems/detect-squares/
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int x;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k)
                pq.pop();
        }
        x=k;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>x)
            pq.pop();
        return pq.top();
    }
};

//Link--https://leetcode.com/problems/kth-largest-element-in-a-stream/
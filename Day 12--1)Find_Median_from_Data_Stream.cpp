class MedianFinder {
public:
    priority_queue<int>a;
    priority_queue<int,vector<int>,greater<int>>b;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(a.size()==b.size())
        {
            if(!b.empty() and num>=b.top())
            {
                a.push(b.top());
                b.pop();
                b.push(num);
            }
            else
                a.push(num);
        }
        else
        {
            if(num>=a.top())
                b.push(num);
            else
            {
                b.push(a.top());
                a.pop();
                a.push(num);
            }
        }
    }
    
    double findMedian() {
        if(a.size()==b.size())
            return (a.top()+b.top())/2.0;
        return a.top();
    }
};

//Link--https://leetcode.com/problems/find-median-from-data-stream/
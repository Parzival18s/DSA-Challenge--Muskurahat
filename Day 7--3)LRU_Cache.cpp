class LRUCache {
public:
    unordered_map<int,int>m;
    unordered_map<int,list<int>::iterator>check;
    list<int>lis;
    int len;
    LRUCache(int capacity) {
        len=capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        
        lis.erase(check[key]);
        lis.push_front(key);
        check[key]=lis.begin();
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            lis.erase(check[key]);
            lis.push_front(key);
            check[key]=lis.begin();
        }
        else
        {
            if(m.size()==len)
            {
                check.erase(lis.back());
                m.erase(lis.back());
                lis.pop_back();
                lis.push_front(key);
                check[key]=lis.begin();
            }
            else
            {
                lis.push_front(key);
                check[key]=lis.begin();
            }
        }
        m[key]=value;
    }
};
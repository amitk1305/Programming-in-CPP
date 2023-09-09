class MyCalendarTwo {
public:
    map<int,int>m;
    MyCalendarTwo() {
        
    }
    //only 2 events allowed to overlap to in map sorted order only two m[start]+m[start] can be allowed
    bool canAdd(int n){
        int cnt=0;
        for(auto it=m.begin();it!=m.end();it++){
            cnt+=it->second;
            if(cnt>n)return false;
        }
        return true;
    }
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        if(canAdd(2))return true;
        else{
            m[start]--;
            m[end]++;
            return false;
        }       
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
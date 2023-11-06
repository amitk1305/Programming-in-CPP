class SeatManager {
public:
    bool A[100001]={0};//Use constraint 1 <= n <= 10^5
    int top;
    int n;
    SeatManager(int n) { // TC: O(n)
        this->n=n;
        fill(A, A+n, 1);
        top=1;
    }
    
    int reserve() { // TC: O(n)
        int x=top++;
        while (top<n && !A[top])
            top++;
        A[x]=0;
        return x;
    }
    
    void unreserve(int seatNumber) {// TC: O(1)
        A[seatNumber]=1;
        if (top>seatNumber) top=seatNumber;
    }
};
/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
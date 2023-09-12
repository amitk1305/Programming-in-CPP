class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        int count=0;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1 && count>0){
                if(count-i==0)
                    ans+=(count)/2;//when substring starts from 0 index
                else
                    ans+=(count-1)/2;//for any normal index other than 0
                if(ans>=n)
                return 1;
                count=0;
            }
            else if(arr[i]==0)
                count++;
        }
        if(count==arr.size())
            ans+=(count+1)/2;//subarray which contains starting as well as ending index
        else if(count>0)
            ans+=(count)/2;//subarray which contains ending index
        if(ans>=n)
            return 1;
        return 0; 
    }
};
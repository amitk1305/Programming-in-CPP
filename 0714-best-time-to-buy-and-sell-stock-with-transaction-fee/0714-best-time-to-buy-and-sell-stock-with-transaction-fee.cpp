class Solution {
public:
    int maximumProfit(vector<int>& prices,int ind,bool canBuy,vector<vector<int>>& strg,int fee){
        if(ind==prices.size()) return 0;
        if(strg[ind][canBuy]!=-1) return strg[ind][canBuy];
        int profit=0;
        if(canBuy){
            int Bought=maximumProfit(prices,ind+1,!canBuy,strg,fee)-prices[ind]-fee;
            int notBought=maximumProfit(prices,ind+1,canBuy,strg,fee);
            profit=max(Bought,notBought);
        }else{
            int Sold=maximumProfit(prices,ind+1,!canBuy,strg,fee)+prices[ind];
            int notSold=maximumProfit(prices,ind+1,canBuy,strg,fee);
            profit=max(Sold,notSold);
        }
        return strg[ind][canBuy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int ind=0;
        bool canBuy=true;
        vector<vector<int>> strg(prices.size()+1,vector<int>(2,-1));
        return maximumProfit(prices,ind,canBuy,strg,fee);
    }
};
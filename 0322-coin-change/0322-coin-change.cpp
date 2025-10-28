class Solution {
public:
    int count(int amount, vector<int>& coins, vector<int> &dp){
        //this will give the number of minimum ways to build that amount
        if(amount<0) return 1e9;
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        
        int minCoins=1e9;
        for(int coin:coins){
            minCoins=min(minCoins,1+count(amount-coin,coins,dp));
        }
        return dp[amount]=minCoins;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1,-1);
        return (count(amount,coins,dp)==1e9)?-1:count(amount,coins,dp);
    }
};
class Solution {
public:
    int climb(int n, vector<int> &costs, vector<int> &dp){
        if(n==0) return 0;
        if(n==1) return dp[n]=costs[n-1]+1;
        if(dp[n]!=-1) return dp[n];
        int a=climb(n-1,costs,dp)+costs[n-1]+1;
        int b=(n-2>=0)?climb(n-2,costs,dp)+costs[n-1]+4:INT_MAX;
        int c=(n-3>=0)?climb(n-3,costs,dp)+costs[n-1]+9:INT_MAX;;
        return dp[n]=min({a,b,c});
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
        dp[0]=0;
        dp[1]=costs[0]+1;
        for(int i=2; i<=n; i++){
            int a=dp[i-1]+1;
            int b=dp[i-2]+4;
            int c=(i-3>=0)?dp[i-3]+9:INT_MAX;
            dp[i]=costs[i-1]+min({a,b,c});
        }
        return dp[n];
    }
};
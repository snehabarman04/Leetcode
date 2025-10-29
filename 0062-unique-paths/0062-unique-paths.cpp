class Solution {
public:
    int countPaths(int x, int y, vector<vector<int>> &dp){
        if(x==0) return dp[x][y]=1;
        if(y==0) return dp[x][y]=1;
        if(dp[x][y]!=-1) return dp[x][y];

        //for any point the no of ways is the sum of ways from the cell above and cell to the left
        return dp[x][y]=countPaths(x-1,y,dp)+countPaths(x,y-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return countPaths(m-1,n-1,dp);
    }
};
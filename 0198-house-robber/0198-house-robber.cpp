class Solution {
public:
    int rob(int ind, vector<int>& nums, vector<int> &dp){
        if(ind<0) return 0;
        if(ind==0) return dp[0]=nums[0];
        if(dp[ind]!=-1) return dp[ind];

        int notTake=rob(ind-1,nums,dp);
        int take=nums[ind]+rob(ind-2,nums,dp);
        return dp[ind]=max(notTake,take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return rob(n-1,nums,dp);
    }
};
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid>0 && mid<n-1){
                if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
                else{
                    int copyInd=mid;
                    if(nums[mid+1]==nums[mid]) copyInd=mid+1;
                    else copyInd=mid-1;
                    if(copyInd%2==0){
                        if(copyInd<mid) low=mid+1;
                        else high=mid-1;
                    }
                    else{
                        if(copyInd<mid) high=mid-1;
                        else low=mid+1;
                    }
                }
            }            
        }
        return -1;
    }
};
class Solution {
public:
    int lowerBound(vector<int> &nums, int target){
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    int upperBound(vector<int> &nums, int target){
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        //the logic is that the first occurence will be the lower bound of the element in the array
        //the last occurence is the index before the upper bound of the element in the array
        int n=nums.size();
        int lb = lowerBound(nums, target);
        int ub = upperBound(nums, target);
        if (lb == -1 || lb >= n || nums[lb] != target) return {-1, -1};
        return {lb, (ub == -1 ? n : ub) - 1};
    }
};
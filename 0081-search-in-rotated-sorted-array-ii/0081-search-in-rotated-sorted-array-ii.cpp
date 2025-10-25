class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //we just need to eliminate the half that is sorted and check if our target in that or not
        int n=nums.size();
        int low=0; 
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return true;
            
            //if we get contiguous duplicates such taht all the three mid, low high are same then we need to trim down the search space
            if(nums[mid]==nums[low] && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }
            //now we find the sorted half
            else{
                if(nums[mid]<=nums[high]){
                    //then the right half is sorted
                    if(target<=nums[high] && target>=nums[mid]){
                        //then we search in the right sorted half
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
                }
                else{
                    //then the left half is sorted
                    if(target<=nums[mid] && target>=nums[low]){
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
            }
        }
        return false;
    }
};
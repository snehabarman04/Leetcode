class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        //the idea is that the part which is sorted will not have the potential to have the minimum
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]==nums[low] && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }
            if(nums[mid]>nums[high]){
                //then minimum lies in the right half
                low=mid+1;
            }            
            else{
                //when the minimum lies in the left half including the mid
                high=mid;
            }
        }
        //when low and high converge then that is the minimum
        return nums[low];
    }
};
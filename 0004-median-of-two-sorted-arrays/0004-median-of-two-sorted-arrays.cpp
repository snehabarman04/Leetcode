class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;

        int onLeft=(n+1)/2;
        int onRight=n-onLeft;

        int low=0;
        int high=n1;
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);

        

        while(low<=high){
            int maxLeft1=INT_MIN,maxLeft2=INT_MIN,minRight1=INT_MAX,minRight2=INT_MAX;
            int mid1=(low+high)/2;
            int mid2=onLeft-mid1;
            if(mid1>0) maxLeft1=nums1[mid1-1];
            if(mid2>0) maxLeft2=nums2[mid2-1];
            if(mid1<n1) minRight1=nums1[mid1];
            if(mid2<n2) minRight2=nums2[mid2];
            if(maxLeft1<=minRight2 && maxLeft2<=minRight1){
                if(n%2==0) return (double)((max(maxLeft1,maxLeft2)+min(minRight1,minRight2))/2.0);
                else return (double)(max(maxLeft1,maxLeft2));
            }
            else if(maxLeft1>minRight2){
                high=mid1-1;
            }
            else{
                low=mid1+1;
            }
        }
        return 0;
    }
};
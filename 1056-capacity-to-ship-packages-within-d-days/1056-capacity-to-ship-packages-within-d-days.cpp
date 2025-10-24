class Solution {
public:
    int daysTaken(vector<int> &v, int capacity){
        int n=v.size();
        int count=1;
        int weightSum=0;
        for(int i=0; i<n; i++){
            if(weightSum+v[i]>capacity){
                weightSum=0;
                count++;
            }
            weightSum+=v[i];
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=INT_MIN, high=0;
        for(int i=0; i<n; i++){
            low=max(low,weights[i]);
            high+=weights[i];
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(daysTaken(weights,mid)>days) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};
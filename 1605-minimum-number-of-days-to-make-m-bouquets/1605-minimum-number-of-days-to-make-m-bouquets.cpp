class Solution {
public:
    int bouquetsPossible(vector<int>& bloomDay, int mid, int k, int m){
        int count=0;
        int n=bloomDay.size();
        int flowersUsed=0;
        for(int day:bloomDay){
            if(day<=mid){
                flowersUsed++;
                if(flowersUsed==k){
                    //then we make a bouquet
                    count++;
                    flowersUsed=0; //reset to zero for next iteration
                }                
            }
            else{
                flowersUsed=0; //reset again
            }
        }
        return count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k>n) return -1;
        int low=*min_element(bloomDay.begin(), bloomDay.end());
        int high=*max_element(bloomDay.begin(), bloomDay.end());
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(bouquetsPossible(bloomDay,mid,k,m)>=m){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
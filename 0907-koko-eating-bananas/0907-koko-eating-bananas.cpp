class Solution {
public:
    int hoursTaken(vector<int> &piles, int capacity, int h){
        int count=0;
        for(int i=0; i<piles.size(); i++){
            if(count>h) return count;
            count+=(piles[i]/capacity);
            if(piles[i]%capacity!=0) count++;
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(), piles.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(hoursTaken(piles,mid,h)>h) low=mid+1;
            else{
                high=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};
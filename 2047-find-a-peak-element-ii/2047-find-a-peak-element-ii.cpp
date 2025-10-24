class Solution {
public:
    int findMaxInd(vector<int> v){
        int ind=-1;
        int max=INT_MIN;
        for(int i=0; i<v.size(); i++){
            if(v[i]>=max){
                ind=i;
                max=v[i];
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int maxInd=findMaxInd(mat[mid]);
            int maxEle=mat[mid][maxInd];
            int up=(mid-1>=0)?mat[mid-1][maxInd]:-1;
            int down=(mid+1<n)?mat[mid+1][maxInd]:-1;
            if(maxEle>up && maxEle>down) return {mid,maxInd};
            else if(up>maxEle) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};
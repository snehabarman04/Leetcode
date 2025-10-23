class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int total=n*m;
        int low=0;
        int high=total-1;
        while(low<=high){
            int mid=(low+high)/2;
            int x=mid/m;
            int y=mid%m;
            if(matrix[x][y]==target) return true;
            else if(matrix[x][y]<target) low=mid+1;
            else high=mid-1;
        }
        return false;

    }
};
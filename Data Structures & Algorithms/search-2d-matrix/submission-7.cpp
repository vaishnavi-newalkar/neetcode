class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l =0;
        int col=matrix[0].size();
        int row=matrix.size();
        int r= col*row -1;
        while(l<=r){
            int mid=(l+r)/2;
            int r_= mid/col, c_=mid%col;
            if(matrix[r_][c_]== target) return true;
            else if(matrix[r_][c_]< target) l=mid+1;
            else r=mid-1;
        }
        return false;
    }
};

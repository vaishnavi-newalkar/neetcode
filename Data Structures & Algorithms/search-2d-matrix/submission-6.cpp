class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col_size=matrix[0].size();
        int size=matrix.size();
        int l=0; bool found = false;
        while(l<size){
            if(matrix[l][0]<=target){ 
                if(matrix[l][col_size-1]>=target){
                    int q=0,r=col_size-1;
                    while(q<=r){
                        int mid=(q+r)/2;
                        if(matrix[l][mid]==target) {return true;}
                        else if(matrix[l][mid]<target) q=mid+1;
                        else r=mid-1;
                    }
                    break;
                }else l++;     
            }
            else break;
        }
        return false;
    }
};

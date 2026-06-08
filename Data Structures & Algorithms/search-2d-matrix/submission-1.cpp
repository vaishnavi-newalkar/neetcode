class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==target) return true;
            else if(matrix[i][0]<target){
                int l=0,r=matrix[i].size()-1;
                while(l<=r)
               { int mid=(l+r)/2;
                if(target==matrix[i][mid]){
                    return true;}
                else if(target>matrix[i][mid]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }    
                }
            }
        }
        return false;
    }
};

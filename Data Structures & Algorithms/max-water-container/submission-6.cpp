class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n= heights.size();
        int l=0,r=n-1;
        int area=INT_MIN;
        while(l<r){
            area=max(area,min(heights[l],heights[r])*(r-l));
            if(heights[l]<heights[r]) l++;
            else if(heights[r]<heights[l])r--;
            else{
                l++;
                r--;
            }
        }
        return area;
    }
};

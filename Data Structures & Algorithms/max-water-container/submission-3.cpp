class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n= heights.size();
        int l=0,r=n-1;
        int area=0;
        while(l<r){
            area=max(((r-l)*(min(heights[r],heights[l]))),area);
            if(heights[l]<heights[r]) l++;
            else r--;
            
        }
        return area;
    }
};

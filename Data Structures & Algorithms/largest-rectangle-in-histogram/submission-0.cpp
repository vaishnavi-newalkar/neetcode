class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int max_area=INT_MIN;
        stack<int> st;
        int n=height.size();
        for(int i=0;i<height.size();i++){
           
           while(!st.empty() && height[i]<height[st.top()]){
            int top=st.top();
            st.pop();
            int h=height[top];
            int left = st.empty() ? -1 : st.top();
            int width=i-left-1;

            int temp=h*width;
            max_area=max(max_area,temp);
           }
           st.push(i);}
           while(!st.empty()){
            int top=st.top();
            st.pop();
            int h=height[top];
            int left = st.empty() ? -1 : st.top();
            int width=n-left-1;
            int temp=h*width;
            max_area=max(max_area,temp);
            

        }
    
        return max_area;
    }
};

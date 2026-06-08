class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> st;
        float time=0.0;
        vector<pair<int,int>> combArray;
        for(int i=0;i<position.size();i++){
            combArray.push_back({position[i],speed[i]});
        }
        sort(combArray.begin(),combArray.end(),greater<pair<int,int>>());
        for(int i=0;i<combArray.size();i++){
            time=(float)(target-combArray[i].first)/combArray[i].second;
            if(st.empty()){
                st.push(time);
            }
            if (time>st.top()){
                st.push(time);
            }

        }
        return st.size();
    }
};

class Solution {
public:

    int distance(vector<int>& v1){
        int q= ((v1[0]-0)*(v1[0]-0)  + (v1[1]-0)*(v1[1]-0) );
        return q;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
        pair<int, vector<int>>,
        vector<pair<int, vector<int>>>,
        greater<pair<int, vector<int>>>
    > pq;

        for(int i=0;i<points.size();i++){
            pq.push({distance(points[i]),points[i]});
        }
        vector<vector<int>>ans;
        while(k--){
           ans.push_back(pq.top().second);
           pq.pop();
        }
        return ans;
    }
};

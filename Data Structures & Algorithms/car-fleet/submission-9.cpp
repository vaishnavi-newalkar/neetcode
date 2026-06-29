class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>> pairs(n);
        for(int i=0;i<speed.size();i++){
            pairs[i]={position[i],speed[i]};
        }
        sort(pairs.begin(),pairs.end());
        vector<double>time(n);
        for(int i=0;i<n;i++){
           time[i]=((target-pairs[i].first)*1.0/pairs[i].second);
        }
        int fleets=1; double lastFleetTime=time[n-1];
        for(int i=n-2;i>=0;i--){
            if(time[i]>lastFleetTime) {
                fleets++;
                lastFleetTime=time[i];
                }
        }
        return fleets;
    }
};

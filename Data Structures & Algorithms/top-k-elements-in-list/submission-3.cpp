class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
         
        for(int i=0;i<nums.size();i++){
          mp[nums[i]]++;
        }
        
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(auto i: mp){
          pq.push({i.second,i.first});
        }

        while(k--){
          ans.push_back(pq.top().second);
          pq.pop();
        } 
        


        return ans;
    }
};

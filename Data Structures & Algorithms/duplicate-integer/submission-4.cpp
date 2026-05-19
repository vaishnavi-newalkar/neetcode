class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i:nums){
            freq[i]++;
        }
        for(auto j:nums){
            if(freq[j]>1){
                return true;
            }
        }
        return false;
    }
};
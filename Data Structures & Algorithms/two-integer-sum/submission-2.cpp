class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
           int q=target-nums[i];
           auto it = find(nums.begin(),nums.end(),q);
           if(it!=nums.end() && it-nums.begin()!=i){
             res.push_back(i);
             res.push_back(it-nums.begin());
             break;
           }
        }
        sort(res.begin(),res.end());
        return res;
    }
};

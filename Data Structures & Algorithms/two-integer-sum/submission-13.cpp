class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];

            if (mp.find(rem) != mp.end()) {
                return {mp[rem], i};   // returns {0,1} for [3,3]
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
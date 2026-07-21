class Solution {
public:
    vector<int> subset;
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int idx, int rem) {

        // Base cases
        if (rem == 0) {
            ans.push_back(subset);
            return;
        }

        if (rem < 0 || idx == nums.size()) {
            return;
        }

        // Take current element (stay at same index)
        subset.push_back(nums[idx]);
        solve(nums, idx, rem - nums[idx]);
        subset.pop_back();

        // Skip current element (move to next index)
        solve(nums, idx + 1, rem);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(nums, 0, target);
        return ans;
    }
};
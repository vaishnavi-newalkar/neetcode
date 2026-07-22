class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void solve(vector<int>& candidates, int idx, int rem) {

        if (rem == 0) {
            ans.push_back(subset);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            // Skip duplicate values at the same level
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > rem)
                break;

            subset.push_back(candidates[i]);

            solve(candidates, i + 1, rem - candidates[i]);

            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        solve(candidates, 0, target);

        return ans;
    }
};
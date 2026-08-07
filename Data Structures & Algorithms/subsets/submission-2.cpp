class Solution {
public:

    vector<vector<int>> ans;
    vector<int> subset;

    void backtrack(int index,vector<int>& nums){
        if(index==nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        backtrack(index+1,nums);
        subset.pop_back();
        backtrack(index+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0,nums);
        return ans;
    }
};

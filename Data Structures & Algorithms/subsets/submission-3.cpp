class Solution {
public:
   
    vector<vector<int>> ans;
    vector<int> ss;

    void backtrack(int idx,vector<int>& nums){
        if(idx==nums.size()){
            ans.push_back(ss);
            return ;
        }
        ss.push_back(nums[idx]);
        backtrack(idx+1,nums);
        ss.pop_back();
        backtrack(idx+1,nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0,nums);
        return ans;
    }
};

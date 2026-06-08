class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int l = 0; l < n-2; l++){

            int mid = l + 1;
            int r = n - 1;

            while(mid < r){

                int sum = nums[l] + nums[mid] + nums[r];

                if(sum == 0){
                    ans.push_back({nums[l], nums[mid], nums[r]});
                    mid++;
                    r--;
                }
                else if(sum > 0){
                    r--;
                }
                else{
                    mid++;
                }
            }
        }

        set<vector<int>> s(ans.begin(), ans.end());
        vector<vector<int>> final_ans(s.begin(), s.end());

        return final_ans;
    }
};
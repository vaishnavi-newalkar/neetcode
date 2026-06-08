class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        int n=nums.size();

        for(int l=0;l<n-2;l++){
            if(l>0 && nums[l]==nums[l-1]) continue;

            int mid=l+1;
            int r=n-1;

            while(mid<r){
                int sum = nums[l]+nums[mid]+nums[r];
                if(sum==0){
                    ans.push_back({nums[l],nums[mid],nums[r]});
                    mid++;
                    r--;

                    while(mid<r && nums[mid]==nums[mid-1]) mid++;
                    while(mid<r && nums[r]== nums[r+1]) r--;
                }
                else if(sum>0){
                    r--;
                }
                else mid++;
            }
        }

        return ans;
    }
};

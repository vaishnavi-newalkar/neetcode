class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        for(int i=0;i<n;i++){
            int l=i+1;
            int r=n-1;
            while(l<r)
            {int sum =nums[i]+nums[l]+nums[r];
            if(sum==0) {ans.insert ({nums[i],nums[l],nums[r]});
            l++;
            r--;}
            else if(sum<0) l++;
            else r--;}
        }
        vector<vector<int>> v(ans.begin(),ans.end());
        return v;
    }
};

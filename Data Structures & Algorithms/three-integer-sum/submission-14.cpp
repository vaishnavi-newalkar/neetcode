class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>> s;
        for(int i=0;i<n;i++){
            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0){
                    vector<int> temp={nums[i],nums[l],nums[r]};
                    s.insert(temp);
                    l++;r--;
                }
                else if(sum<0){
                    l++;
                }
                else r--;
            }
        }
        vector<vector<int>> v(s.begin(),s.end());
        return v;
    }
};

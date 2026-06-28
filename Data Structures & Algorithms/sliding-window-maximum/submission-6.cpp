class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0;
        int r=k-1;
        vector<int> maxELE;
        while(r<nums.size()){
            int mx = *max_element(nums.begin() + l, nums.begin() + r + 1);
             maxELE.push_back(mx);
             l++;
             r++;
        }
        return maxELE;
    }
};

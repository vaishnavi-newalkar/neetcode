class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> vis(nums.size(), false);

        for (int x : nums) {
            if (vis[x])
                return x;
            vis[x] = true;
        }

        return -1;
    }
};
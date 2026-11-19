class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int ans = 0;

        while (r < prices.size()) {
            if (prices[r] < prices[l]) {
                l = r;  // find a better buying day
            } else {
                ans = max(ans, prices[r] - prices[l]);
            }
            r++;
        }

        return ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int min_price=prices[0];
        int l=0;
        for(int r=0;r<prices.size();r++){
            profit=max(profit,prices[r]-min_price);
            min_price=min(min_price,prices[r]);
        }

    return profit;
    }
};

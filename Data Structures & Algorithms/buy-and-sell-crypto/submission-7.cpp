class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int profit=0;
        for(int i=1;i<prices.size();i++){
           
            if(prices[l]>prices[i]){
                l=i;
            }
            else{
                profit=max(profit,prices[i]-prices[l]);
            }
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int profit=0;
        for(int i=1;i<prices.size();i++){
            if((prices[i]-prices[l])>profit){
                profit=prices[i]-prices[l];
            }
            while(prices[l]>prices[i]){
                l++;
            }
        }
        return profit;
    }
};

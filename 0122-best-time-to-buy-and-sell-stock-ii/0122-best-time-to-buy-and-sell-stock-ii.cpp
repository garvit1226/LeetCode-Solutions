class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> ahead(2,0), curr(2,0);
        for(int idx= prices.size()-1;idx>=0;idx--){
            for(int buy =0;buy<=1;buy++){
                int profit;
                if(buy){
                    profit = max(-prices[idx]+ ahead[0], ahead[1]);
                }
                else{
                    profit = max(prices[idx]+ ahead[1], ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};
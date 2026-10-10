class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> ahead(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        for(int idx= prices.size()-1;idx>=0;idx--){
            for(int buy =0;buy<=1;buy++){
                for(int cap= 1;cap<=k;cap++){
                int profit;
                if(buy){
                    profit = max(-prices[idx]+ ahead[0][cap], ahead[1][cap]);
                }
                else{
                    profit = max(prices[idx]+ ahead[1][cap-1], ahead[0][cap]);
                }
                curr[buy][cap] = profit;
                }
            }
            ahead = curr;
        }
        return ahead[1][k];
    }
};
class Solution {
public:
    int coinChange(vector<int>& coins, int T) {
        int n = coins.size();
        vector<int> prev(T+1,0);
        for(int tar=0;tar<=T;tar++){
            if(tar%coins[0]==0){
                prev[tar]= tar/coins[0];
            }
            else{
                prev[tar] = 1e9;
            }

        }

        for(int i=1;i<n;i++){
            vector<int> curr(T+1,0);
            for(int tar=0;tar<=T;tar++){
                int nottake = prev[tar];
                int take = 1e9;
                if(coins[i]<=tar){
                    take  = 1 + curr[tar-coins[i]];
                }
                curr[tar] = min(take,nottake);
            }
            prev=curr;
        }
        if(prev[T]>=1e9) return -1;
        return prev[T];
    }
};
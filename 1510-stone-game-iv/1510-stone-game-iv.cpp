class Solution {
public:
        int dp[100001];
        int help(int n){
            if(n<=0) return 0;
            if(dp[n]!=-1) return dp[n];
            for(int i=1;i*i<=n;i++){
                if(help(n-i*i)==0){
                    return dp[n] =1;
                }
            
            }
            return dp[n] =0;
        }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return help(n);
    }
};
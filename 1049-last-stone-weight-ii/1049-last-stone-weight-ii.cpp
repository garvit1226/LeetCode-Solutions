class Solution {
public:
    int lastStoneWeightII(vector<int>& nums) {
        int sum=0;
        int n = nums.size();
        for(int i:nums){
            sum+= i;
        }

        vector<vector<bool>> dp(n,vector<bool> (sum+1,false));
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        if(nums[0]<=sum){
            dp[0][nums[0]] = true;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool nottake = dp[i-1][j];
                bool take=false;
                if(nums[i]<=j){
                    take= dp[i-1][j-nums[i]];
                }
                dp[i][j] = take|nottake;
            }
        }
        int mini = INT_MAX;
        for(int i=0;i<=sum/2;i++){
            if(dp[n-1][i]==true){
                mini= min(mini, abs(sum-i-i));
            }
        }
        return mini;
    }
};
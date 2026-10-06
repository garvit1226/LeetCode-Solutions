class Solution {
public:
    int solve(int i, vector<int>& sum, vector<int>& dp) {
        if (i <= 0)
            return 0;

        if (dp[i] != -1)
            return dp[i];

      
        int take = sum[i] + solve(i - 2, sum, dp);

     
        int notTake = solve(i - 1, sum, dp);

        return dp[i] = max(take, notTake);
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> sum(maxi + 1, 0);

        for (int x : nums) {
            sum[x] += x;
        }

        vector<int> dp(maxi + 1, -1);

        return solve(maxi, sum, dp);
    }
};
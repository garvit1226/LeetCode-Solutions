class Solution {
private:

    int solve(const vector<int>& arr, int amt, int n,
              vector<vector<int>>& dp) {

        // Successfully formed the amount
        if (amt == 0) {
            return 1;
        }

        // No coins left or amount became negative
        if (n < 0 || amt < 0) {
            return 0;
        }

        // Already calculated
        if (dp[n][amt] != -1) {
            return dp[n][amt];
        }

        int take = 0;

        // Take current coin
        // n remains same because we can reuse the coin
        if (arr[n] <= amt) {
            take = solve(arr, amt - arr[n], n, dp);
        }

        // Don't take current coin
        int not_take = solve(arr, amt, n - 1, dp);

        return dp[n][amt] = take + not_take;
    }

public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(amount + 1, -1)
        );

        return solve(coins, amount, n - 1, dp);
    }
};
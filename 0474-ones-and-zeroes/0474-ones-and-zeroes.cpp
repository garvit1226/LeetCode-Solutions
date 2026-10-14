
class Solution {
public:
    int f(int i, int m, int n, vector<string>& strs,
          vector<vector<vector<int>>>& dp) {

        if (i == 0) {
            int zeros = 0, ones = 0;

            for (char c : strs[0]) {
                if (c == '0') zeros++;
                else ones++;
            }

            if (zeros <= m && ones <= n) return 1;
            return 0;
        }

        if (dp[i][m][n] != -1)
            return dp[i][m][n];

        int notTake = f(i - 1, m, n, strs, dp);

        int zeros = 0, ones = 0;
        for (char c : strs[i]) {
            if (c == '0') zeros++;
            else ones++;
        }

        int take = 0;
        if (zeros <= m && ones <= n) {
            take = 1 + f(i - 1, m - zeros, n - ones, strs, dp);
        }

        return dp[i][m][n] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();

        vector<vector<vector<int>>> dp(
            sz, vector<vector<int>>(
                m + 1, vector<int>(n + 1, -1)
            )
        );

        return f(sz - 1, m, n, strs, dp);
    }
};

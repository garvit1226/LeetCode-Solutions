class Solution {
public:
    int f(int i, int j, vector<vector<int>>& dp,
          vector<vector<int>>& a) {

        if(j < 0 || j >= a[0].size())
            return 1e9;

        if(i == 0)
            return a[0][j];

        if(dp[i][j] != 1e9)
            return dp[i][j];

        int up = f(i - 1, j, dp, a);
        int left = f(i - 1, j - 1, dp, a);
        int right = f(i - 1, j + 1, dp, a);

        return dp[i][j] =
            a[i][j] + min({up, left, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 1e9));

        int ans = 1e9;

        for(int j = 0; j < n; j++) {
            ans = min(ans, f(m - 1, j, dp, matrix));
        }

        return ans;
    }
};
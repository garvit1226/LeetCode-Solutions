class Solution {
public:
    int n;
    vector<vector<vector<double>>> dp;

    double f(int r, int c, int k) {
        
        if (r < 0 || r >= n || c < 0 || c >= n)
            return 0.0;

        
        if (k == 0)
            return 1.0;

        if (dp[r][c][k] != -1.0)
            return dp[r][c][k];

        int dr[8] = {2, 2, -2, -2, 1, 1, -1, -1};
        int dc[8] = {1, -1, 1, -1, 2, -2, 2, -2};

        double ans = 0.0;

        for (int i = 0; i < 8; i++) {
            ans += f(r + dr[i], c + dc[i], k - 1) / 8.0;
        }

        return dp[r][c][k] = ans;
    }

    double knightProbability(int n, int k, int row, int column) {
        this->n = n;

        dp.resize(n, vector<vector<double>>(
            n, vector<double>(k + 1, -1.0)
        ));

        return f(row, column, k);
    }
};
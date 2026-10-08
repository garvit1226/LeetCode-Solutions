class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int f(int i, int j1, int j2, vector<vector<int>>& grid) {

        // Out of bounds
        if(j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
            return -1e9;

        // Last row
        if(i == m - 1) {
            if(j1 == j2)
                return grid[i][j1];

            return grid[i][j1] + grid[i][j2];
        }

       
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = -1e9;

        
        for(int d1 = -1; d1 <= 1; d1++) {
            for(int d2 = -1; d2 <= 1; d2++) {

                int value;

                if(j1 == j2)
                    value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];

                value += f(i + 1, j1 + d1, j2 + d2, grid);

                maxi = max(maxi, value);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        dp.resize(m, vector<vector<int>>(
            n, vector<int>(n, -1)
        ));

        return f(0, 0, n - 1, grid);
    }
};
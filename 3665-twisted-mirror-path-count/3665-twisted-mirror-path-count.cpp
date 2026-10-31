class Solution {
public:
    int n;
    int m;
    int MOD = 1e9+7;
    vector<vector<vector<int>>> dp;
    int uniquePaths(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
        dp.assign(n,vector<vector<int>>(m,vector<int>(2,-1)));

        return (f(0,0,0,grid))%MOD;
    }
    int f(int i,int j, int d, vector<vector<int>>& grid){
        if(i>=n || j>=m) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j][d]!=-1) return dp[i][j][d];

        long long ans=0;
        if(grid[i][j]==0) {
            ans+= f(i,j+1,0,grid);
            ans+= f(i+1,j,1,grid);
        }
        else if(grid[i][j]==1){
            if(d==0){
                ans += f(i+1,j,1,grid);
            }
            else{
                ans+= f(i,j+1,0,grid);
            }
        }

        return dp[i][j][d]= ans%MOD;
    }
};
class Solution {
public:
    void helper(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};

        vis[r][c] =1;

        for(int i=0;i<4;i++){
            int nr = r+ delrow[i];
            int nc = c+ delcol[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                helper(nr,nc,grid,vis);
            }
        } 
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                helper(i,0,grid,vis);
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                helper(i,m-1,grid,vis);
            }
        }

        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                helper(0,j,grid,vis);
            }
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                helper(n-1,j,grid,vis);
            }
        }

        int ans =0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};
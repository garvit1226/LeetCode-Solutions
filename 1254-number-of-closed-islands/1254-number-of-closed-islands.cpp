class Solution {
public:
    int m;
    int n;
    void dfs(int i, int j, vector<vector<int>> &grid){
        if(i<0 || j<0 || i>=n || j>=m){
            return;
        }
        if(grid[i][j]==1) return;

        grid[i][j] =1;

        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for(int i=0;i<n;i++){
            dfs(i,0,grid);
            dfs(i,m-1,grid);
        }
        for(int j=0;j<m;j++){
            dfs(0,j,grid);
            dfs(n-1,j,grid);
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};
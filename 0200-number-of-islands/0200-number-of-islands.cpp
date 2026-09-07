class Solution {
public:
    void helper(int i,int j,vector<vector<char>>& grid, vector<vector<bool>> &vis,int n,int m){
        if(i<0 || j<0|| i>=n|| j>=m|| grid[i][j]!='1'|| vis[i][j]){
            return;
        }
        vis[i][j] = true;
        // right
        helper(i,j+1,grid,vis,n,m);
        // left
        helper(i,j-1,grid,vis,n,m);
        // top
        helper(i-1,j,grid,vis,n,m);
        // bottom
        helper(i+1,j,grid,vis,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    
                    ans++;
                    helper(i,j,grid,vis,n,m);

                }
            }
        }
        return ans;
    }
};
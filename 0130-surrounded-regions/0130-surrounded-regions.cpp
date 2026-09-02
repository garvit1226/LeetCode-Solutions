class Solution {
public:
    void dfs(int row, int col,vector<vector<char>>& board, vector<vector<int>> & vis ){
        int n = board.size();
        int m = board[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};

        vis[row][col] =1;
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                dfs(nrow,ncol,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]== 'O'){
                dfs(i,0,board,vis);
            }
            if(!vis[i][m-1] && board[i][m-1]== 'O'){
                dfs(i,m-1,board,vis);
            }
            
        }
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i]== 'O'){
                dfs(0,i,board,vis);
            }
            if(!vis[n-1][i] && board[n-1][i]== 'O'){
                dfs(n-1,i,board,vis);
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> dist(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j] = true;
                    
                    q.push({{i,j},0});
                }
            }
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};

        while(!q.empty()){
            int row= q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();

            dist[row][col]= step;
            step++;

            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                    vis[nrow][ncol] = true;
                    q.push({{nrow,ncol},step});
                }
            }
        }
        return dist;
    }
};
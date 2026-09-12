class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int  n = grid.size();
        int m = grid.size();

        vector<vector<int>> dist(n,vector<int> (m,1e9));
        if(grid[0][0] || grid[n-1][m-1]) return -1;
        dist[0][0] =1;
        q.push({1,{0,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r==n-1 && c==m-1) return d;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr = r+i;
                    int nc = c+j;
                    if(nr>=0 && nc>=0 && nr<n && nc<m && !grid[nr][nc] && dist[r][c] +1 <dist[nr][nc]){
                        dist[nr][nc] = dist[r][c] +1;
                        q.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};
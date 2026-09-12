class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,1e9));

        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,-1,0,1};
        while(!pq.empty()){
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;

            pq.pop();

            if(r==n-1 && c==m-1) return d;

            for(int i=0;i<4;i++){
                int nr = r+ dr[i];
                int nc = c+ dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int newdist = max(abs(heights[r][c] - heights[nr][nc]),d);
                    if(newdist < dist[nr][nc]){
                        dist[nr][nc]= newdist;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }


        }
        return -1;
    }
}; 
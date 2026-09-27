class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

       
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = grid[0][0];

        pq.push({grid[0][0], {0, 0}});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [time, cell] = pq.top();
            pq.pop();

            int r = cell.first;
            int c = cell.second;

            if (r == n - 1 && c == n - 1) {
                return time;
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {

                    
                    int newTime = max(time, grid[nr][nc]);

                    if (newTime < dist[nr][nc]) {
                        dist[nr][nc] = newTime;
                        pq.push({newTime, {nr, nc}});
                    }
                }
            }
        }

        return -1;
    }
};
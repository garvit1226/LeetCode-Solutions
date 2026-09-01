class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int cnt = 0;

        
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        
        if (cnt == 0)
            return 0;

        int all = (1 << cnt) - 1;

       
        queue<array<int, 4>> q;

        q.push({sr, sc, energy, 0});

     
        bool vis[20][20][51][1 << 10] = {false};

        vis[sr][sc][energy][0] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

          
            while (size--) {

                auto [r, c, e, mask] = q.front();
                q.pop();

              
                if (mask == all)
                    return moves;

               
                if (e == 0)
                    continue;

                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                
                    if (classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                   
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

           
                    if (classroom[nr][nc] == 'L') {
                        int bit = id[nr][nc];
                        nmask |= (1 << bit);
                    }

                 
                    if (!vis[nr][nc][ne][nmask]) {

                        vis[nr][nc][ne][nmask] = true;

                        q.push({
                            nr,
                            nc,
                            ne,
                            nmask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};
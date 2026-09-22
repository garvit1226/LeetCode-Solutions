class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)
            return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v]+= size[ulp_u];
        }

        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
public:

    bool isValid(int r, int c, int n) {
        return r >= 0 && r < n &&
               c >= 0 && c < n;
    }

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        DisjointSet ds(n * n);

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        

        for(int r = 0; r < n; r++) {

            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 0)
                    continue;

                int node = r * n + c;

                for(int i = 0; i < 4; i++) {

                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(isValid(nr, nc, n) &&
                       grid[nr][nc] == 1) {

                        int adjNode = nr * n + nc;

                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        int ans = 0;

       

        for(int r = 0; r < n; r++) {

            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 1)
                    continue;

                set<int> components;

                
                for(int i = 0; i < 4; i++) {

                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(isValid(nr, nc, n) &&
                       grid[nr][nc] == 1) {

                        int adjNode = nr * n + nc;

                        int root = ds.findUPar(adjNode);

                        components.insert(root);
                    }
                }

               
                int islandSize = 1;

                for(auto root : components) {
                    islandSize += ds.size[root];
                }

                ans = max(ans, islandSize);
            }
        }

        

        for(int i = 0; i < n * n; i++) {

            if(ds.findUPar(i) == i) {
                ans = max(ans, ds.size[i]);
            }
        }

        return ans;
    }
};
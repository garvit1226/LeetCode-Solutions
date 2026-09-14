class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;

        vector<pair<int, int>> adj[n];

        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {

            long long w = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {

                int child = it.first;
                int ewd = it.second;

                // Shorter path found
                if (w + ewd < dist[child]) {

                    dist[child] = w + ewd;

                    ways[child] = ways[node];

                    pq.push({dist[child], child});
                }

                // Another shortest path found
                else if (w + ewd == dist[child]) {

                    ways[child] =
                        (ways[child] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
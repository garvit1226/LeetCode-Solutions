class Solution {
public:
    int LOG;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, pref;
    vector<int> bit;
    int timer = 0;

    int getBit(char c) {
        return 1 << (c - 'a');
    }

    void add(int i, int val, int n) {
        while (i <= n) {
            bit[i] ^= val;
            i += i & -i;
        }
    }

    int sum(int i) {
        int ans = 0;
        while (i > 0) {
            ans ^= bit[i];
            i -= i & -i;
        }
        return ans;
    }

    void rangeUpdate(int l, int r, int val, int n) {
        add(l, val, n);
        if (r + 1 <= n)
            add(r + 1, val, n);
    }

    void dfs(int u, int p, string &s) {
        tin[u] = ++timer;
        up[0][u] = p;

        pref[u] = (u == p ? 0 : pref[p]) ^ getBit(s[u]);
        depth[u] = (u == p ? 0 : depth[p] + 1);

        // Reverse order is unnecessary; it just preserves adjacency order.
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, s);
        }

        tout[u] = timer;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int k = 0; k < LOG; k++) {
            if (diff & (1 << k))
                u = up[k][u];
        }

        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }

        return up[0][u];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        pref.assign(n, 0);

        LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        up.assign(LOG, vector<int>(n, 0));
        bit.assign(n + 1, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, 0, s);

        for (int k = 1; k < LOG; k++) {
            for (int u = 0; u < n; u++) {
                up[k][u] = up[k - 1][up[k - 1][u]];
            }
        }

        vector<bool> ans;

        for (string &q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int delta = getBit(s[u]) ^ getBit(c);

                rangeUpdate(tin[u], tout[u], delta, n);

                s[u] = c;
            } 
            else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int maskU = pref[u] ^ sum(tin[u]);
                int maskV = pref[v] ^ sum(tin[v]);

                int pathMask =
                    maskU ^ maskV ^ getBit(s[w]);

                // At most one character can have an odd frequency.
                ans.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return ans;
    }
};
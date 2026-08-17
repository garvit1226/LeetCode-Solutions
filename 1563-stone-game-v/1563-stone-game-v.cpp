class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + stoneValue[i];

        vector<vector<int>> memo(n, vector<int>(n, -1));

        function<int(int,int)> dfs = [&](int l, int r) {
            if (l == r) return 0;

            if (memo[l][r] != -1)
                return memo[l][r];

            int ans = 0;

            for (int k = l; k < r; k++) {
                int left = pref[k + 1] - pref[l];
                int right = pref[r + 1] - pref[k + 1];

                if (left < right) {
                    ans = max(ans, left + dfs(l, k));
                } else if (left > right) {
                    ans = max(ans, right + dfs(k + 1, r));
                } else {
                    ans = max(ans,
                              max(left + dfs(l, k),
                                  right + dfs(k + 1, r)));
                }
            }

            return memo[l][r] = ans;
        };

        return dfs(0, n - 1);
    }
};
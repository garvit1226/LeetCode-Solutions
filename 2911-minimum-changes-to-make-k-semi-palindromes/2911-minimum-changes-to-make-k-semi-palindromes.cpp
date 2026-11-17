
class Solution {
public:
    int minimumChanges(string s, int k) {

        int n = s.size();
        int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        // Precompute semi-palindrome costs
        for(int l = 0; l < n; l++) {

            for(int r = l + 1; r < n; r++) {

                int len = r - l + 1;

                for(int d = 1; d < len; d++) {

                    if(len % d != 0) continue;

                    int changes = 0;

                    for(int rem = 0; rem < d; rem++) {

                        int i = l + rem;
                        int j = l + rem + ((len - 1 - rem) / d) * d;

                        while(i < j) {

                            if(s[i] != s[j])
                                changes++;

                            i += d;
                            j -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        // Partition DP
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for(int parts = 1; parts <= k; parts++) {

            for(int i = 2 * parts; i <= n; i++) {

                for(int t = 2 * (parts - 1); t <= i - 2; t++) {

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[t][parts - 1] + cost[t][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};

class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        int mod = 1e9 + 7;

        vector<long long> dp(n + 1);
        vector<int> last(26, -1);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            char ch = s[i - 1];

            dp[i] = (2 * dp[i - 1]) % mod;

            if (last[ch - 'a'] != -1) {
                int prev = last[ch - 'a'];

                dp[i] = (dp[i] - dp[prev] + mod) % mod;
            }

            last[ch - 'a'] = i - 1;
        }

        // Remove empty subsequence
        return (dp[n] - 1 + mod) % mod;
    }
};
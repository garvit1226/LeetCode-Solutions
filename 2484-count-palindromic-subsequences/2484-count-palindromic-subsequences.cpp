class Solution {
public:
    int MOD = 1e9 + 7;
    int n;
    string s;
    int dp[10001][6][10][10];

    int f(int i, int len, int a, int b) {
        if (len == 5) return 1;
        if (i == n) return 0;

        int &res = dp[i][len][a][b];
        if (res != -1) return res;

        long long ans = f(i + 1, len, a, b);

        int d = s[i] - '0';

        if (len == 0) {
            ans += f(i + 1, len + 1, d, b);
        } 
        else if (len == 1) {
            ans += f(i + 1, len + 1, a, d);
        } 
        else if (len == 2) {
            ans += f(i + 1, len + 1, a, b);
        } 
        else if (len == 3 && d == b) {
            ans += f(i + 1, len + 1, a, b);
        } 
        else if (len == 4 && d == a) {
            ans += f(i + 1, len + 1, a, b);
        }

        return res = ans % MOD;
    }

    int countPalindromes(string str) {
        s = str;
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return f(0, 0, 0, 0);
    }
};
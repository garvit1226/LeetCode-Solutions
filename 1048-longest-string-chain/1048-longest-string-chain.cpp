class Solution {
public:
    bool compare(string &s2,string &s1 ){
        if(s1.size()+1 != s2.size()) return false;
        int i=0, j=0;
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                i++;
            }
            j++;
        }

        return i == s1.size();

    }
    static bool cmp(const string &a, const string &b) {
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int ans =0;
        vector<int> dp(n,1);
        sort(words.begin(), words.end(), cmp);
        for(int i=0;i<n;i++){
            for(int pre =0; pre<i;pre++){
                if(compare(words[i], words[pre]) && 1+ dp[pre]>dp[i]){
                    dp[i] = 1 + dp[pre];
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
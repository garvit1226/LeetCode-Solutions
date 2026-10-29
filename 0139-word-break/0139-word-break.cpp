class Solution {
public:
    int n;
    bool f(string s, vector<int>& dp, int i, vector<string> &wordDict){
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i];
        for(string word: wordDict){
            int len = word.size();
            if(i+len<=n && s.substr(i,len)==word){
                if(f(s,dp,i+len,wordDict)){
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         n = s.size();
         vector<int> dp(n,-1);
         return f(s,dp,0,wordDict);
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),1e9));
        return f(0,0,dp,triangle);
    }

    int f(int i,int j,vector<vector<int>>& dp, vector<vector<int>>& triangle){
        if(i==triangle.size()-1) return triangle[i][j];
        if(dp[i][j]!=1e9) return dp[i][j];
        int down = triangle[i][j] + f(i+1,j,dp,triangle);
        int dia = triangle[i][j] + f(i+1,j+1,dp,triangle);
        return dp[i][j] = min(down,dia);
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums.size()-1, nums, dp);
    }
    int f(int i, vector<int> nums, vector<int> &dp){
        if(i==0) return nums[0];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take = nums[i] + f(i-2,nums,dp);
        int nottake = f(i-1,nums,dp);

        return dp[i] = max(take, nottake);
    }
};
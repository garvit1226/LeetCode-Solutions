
class Solution {
public:
    int f(int i, int tar, vector<int>& nums,
          vector<vector<int>>& dp) {

        if (i == 0) {
            if (tar == 0) return 0;
            if (nums[0] == tar) return 1;
            return -1e9;
        }

        if (dp[i][tar] != -1)
            return dp[i][tar];

        int notTake = f(i - 1, tar, nums, dp);

        int take = -1e9;
        if (nums[i] <= tar) {
            int res = f(i - 1, tar - nums[i], nums, dp);
            if (res != -1e9)
                take = 1 + res;
        }

        return dp[i][tar] = max(take, notTake);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> dp(
            n, vector<int>(target + 1, -1)
        );

        int ans = f(n - 1, target, nums, dp);
        return ans < 0 ? -1 : ans;
    }
};

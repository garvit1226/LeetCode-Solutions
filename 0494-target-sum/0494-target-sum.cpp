
class Solution {
public:
    int f(int i, int tar, vector<int>& nums,
          vector<vector<int>>& dp) {

        if (i == 0) {
            if (tar == 0 && nums[0] == 0) return 2;
            if (tar == 0 || tar == nums[0]) return 1;
            return 0;
        }

        if (dp[i][tar] != -1)
            return dp[i][tar];

        int notTake = f(i - 1, tar, nums, dp);

        int take = 0;
        if (nums[i] <= tar) {
            take = f(i - 1, tar - nums[i], nums, dp);
        }

        return dp[i][tar] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int x : nums) sum += x;

        if (abs(target) > sum) return 0;
        if ((sum + target) % 2 != 0) return 0;

        int tar = (sum + target) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));

        return f(n - 1, tar, nums, dp);
    }
};

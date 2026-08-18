class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        
        if (k == 1) {
            unordered_map<int, int> freq;

            for (int x : nums)
                freq[x]++;

            int ans = -1;

            for (auto it : freq) {
                if (it.second == 1)
                    ans = max(ans, it.first);
            }

            return ans;
        }

        
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        
        int ans = -1;

        
        bool first = true;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[0]) {
                first = false;
                break;
            }
        }

        if (first)
            ans = max(ans, nums[0]);

        
        bool last = true;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[n - 1]) {
                last = false;
                break;
            }
        }

        if (last)
            ans = max(ans, nums[n - 1]);

        return ans;
    }
};
class Solution {
public:
    bool possible(vector<int>& nums, int k, int cap) {
        int count = 0;
        int i = 0;

        while (i < nums.size()) {
            if (nums[i] <= cap) {
                count++;
                i += 2;  
            } else {
                i++;
            }

            if (count >= k)
                return true;
        }

        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans =-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(nums, k, mid)) {
                high = mid-1;
                ans = mid;     
            } else {
                low = mid + 1;    
            }
        }

        return ans;
    }
};

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        long long k = 1LL * k1 + k2;
        int n = nums1.size();

        vector<int> diff(n);
        int mx = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
            sum += diff[i];
        }

     
        if (sum <= k) return 0;

        int low = 0, high = mx;

       
        while (low < high) {
            int mid = low + (high - low) / 2;
            long long needed = 0;

            for (int d : diff) {
                if (d > mid) {
                    needed += d - mid;
                }
            }

            if (needed <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int threshold = low;

       
        long long remaining = k;

        for (int& d : diff) {
            if (d > threshold) {
                remaining -= d - threshold;
                d = threshold;
            }
        }

        
        for (int& d : diff) {
            if (remaining > 0 && d == threshold) {
                d--;
                remaining--;
            }
        }

        long long ans = 0;

        for (int d : diff) {
            ans += 1LL * d * d;
        }

        return ans;
    }
};

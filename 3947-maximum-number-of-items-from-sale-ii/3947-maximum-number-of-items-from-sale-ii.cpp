
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        for (auto &it : items) {
            freq[it[0]]++;
            minPrice = min(minPrice, it[1]);
        }

        vector<int> gain(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                gain[i] += freq[j];
            }
            gain[i]--; // Exclude itself
        }

        sort(items.begin(), items.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long rem = budget;

        for (auto &it : items) {
            int factor = it[0];
            int price = it[1];

            if (price >= 2LL * minPrice)
                break;

            long long cnt = min(
                (long long)gain[factor],
                rem / price
            );

            ans += 2 * cnt;
            rem -= cnt * price;
        }

       
        ans += rem / minPrice;

        return (int)ans;
    }
};


class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sqsum = 0;
        long long lazy = 0;
    };

    vector<Node> seg;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        seg[node].sqsum = (
            seg[node].sqsum
            + 2LL * val * seg[node].sum % MOD
            + val * val % MOD * len % MOD
        ) % MOD;

        seg[node].sum = (
            seg[node].sum + val * len
        ) % MOD;

        seg[node].lazy = (seg[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0 || l == r)
            return;

        int mid = (l + r) / 2;
        long long val = seg[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        seg[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long val) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        seg[node].sum = (
            seg[node * 2].sum +
            seg[node * 2 + 1].sum
        ) % MOD;

        seg[node].sqsum = (
            seg[node * 2].sqsum +
            seg[node * 2 + 1].sqsum
        ) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n, Node());

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = -1;

            if (last.count(nums[i]))
                prev = last[nums[i]];

            
            update(1, 0, n - 1, prev + 1, i, 1);

            
            ans = (ans + seg[1].sqsum) % MOD;

            last[nums[i]] = i;
        }

        return ans;
    }
};

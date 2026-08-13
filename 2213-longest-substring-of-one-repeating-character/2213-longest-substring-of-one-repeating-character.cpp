class Solution {
public:

    struct Node {
        int len;
        int left;
        int right;
        int best;
        char lc, rc;

        Node() {
            len = left = right = best = 0;
            lc = rc = '#';
        }

        Node(char c) {
            len = left = right = best = 1;
            lc = rc = c;
        }
    };

    vector<Node> seg;
    string s;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        // Prefix
        res.left = a.left;

        if (a.left == a.len && a.rc == b.lc) {
            res.left = a.len + b.left;
        }

        // Suffix
        res.right = b.right;

        if (b.right == b.len && a.rc == b.lc) {
            res.right = b.len + a.right;
        }

        // Best answer inside either half
        res.best = max(a.best, b.best);

        // Best substring crossing the boundary
        if (a.rc == b.lc) {
            res.best = max(res.best, a.right + b.left);
        }

        return res;
    }

    void build(int idx, int low, int high) {

        if (low == high) {
            seg[idx] = Node(s[low]);
            return;
        }

        int mid = (low + high) / 2;

        build(2 * idx, low, mid);
        build(2 * idx + 1, mid + 1, high);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int low, int high, int pos, char c) {

        if (low == high) {
            seg[idx] = Node(c);
            return;
        }

        int mid = (low + high) / 2;

        if (pos <= mid)
            update(2 * idx, low, mid, pos, c);
        else
            update(2 * idx + 1, mid + 1, high, pos, c);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        this->s = s;

        int n = s.size();

        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {

            int pos = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, pos, c);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};
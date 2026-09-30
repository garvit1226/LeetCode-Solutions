class Solution {
public:
    pair<int, int> solve(TreeNode* root) {
        if (root == NULL)
            return {0, 0};

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        
        int notRob = max(left.first, left.second)
                    + max(right.first, right.second);

       
        int rob = root->val
                + left.first
                + right.first;

        return {notRob, rob};
    }

    int rob(TreeNode* root) {
        pair<int, int> ans = solve(root);

        return max(ans.first, ans.second);
    }
};
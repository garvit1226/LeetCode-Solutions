class Solution {
public:
    void helper(TreeNode* root, int target, vector<int>& path,
                vector<vector<int>>& ans) {

        if (root == NULL)
            return;

        path.push_back(root->val);
        target -= root->val;

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            if (target == 0) {
                ans.push_back(path);
            }

            path.pop_back();  // backtrack
            return;
        }

        helper(root->left, target, path, ans);
        helper(root->right, target, path, ans);

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        helper(root, targetSum, path, ans);

        return ans;
    }
};
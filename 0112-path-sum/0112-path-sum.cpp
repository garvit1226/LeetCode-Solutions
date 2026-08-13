class Solution {
public:
    bool helper(TreeNode* root, int target, int sum) {
        if (root == NULL)
            return false;

        sum += root->val;

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            return sum == target;
        }

        return helper(root->left, target, sum) ||
               helper(root->right, target, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum, 0);
    }
};
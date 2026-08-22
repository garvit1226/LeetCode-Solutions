/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans =0;
    vector<int> dfs(TreeNode* root){
        if(root==NULL) return {1,INT_MAX, INT_MIN, 0};
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        if(left[0] && right[0] && left[2]<root->val && right[1]> root->val){
            int sum = left[3]+ right[3]+root->val;
            ans = max(ans,sum);
            int mi = min(root->val, left[1]);
            int ma = max(root->val, right[2]);
            return {1,mi,ma,sum};

        }
        return {0,0,0,0};
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
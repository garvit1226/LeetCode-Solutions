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
    int ans =-1;
    void helper(TreeNode* root, int k , int & cnt){
        if(root==NULL) return ;
        helper(root->left,k,cnt);
        if(ans!=-1) return;
        cnt++;
        if(cnt==k){
            ans = root->val;
            return;
        }
        helper(root->right,k,cnt);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        helper(root,k,cnt);
        return ans;
    }
};
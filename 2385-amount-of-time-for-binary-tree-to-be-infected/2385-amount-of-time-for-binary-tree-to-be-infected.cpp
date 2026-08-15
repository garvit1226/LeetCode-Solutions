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
    int helper2(TreeNode* root, unordered_map<TreeNode* , TreeNode*>& mpp, TreeNode* tar){
        queue<TreeNode*> q;
        int ans =0;
        unordered_map<TreeNode*, int> vis;
        vis[tar] =1;
        q.push(tar);
        while(!q.empty()){
            int temp=0;
            int n = q.size();
            for(int i=0;i<n;i++){
            auto node = q.front();
            q.pop();
            if(node->left && !vis[node->left]){
                temp=1;
                vis[node->left]=1;
                q.push(node->left);
            }
            if(node->right && !vis[node->right]){
                temp=1;
                vis[node->right]=1;
                q.push(node->right);
            }
            if(mpp[node] && !vis[mpp[node]]){
                temp=1;
                vis[mpp[node]]=1;
                q.push(mpp[node]);
            }
            }
            ans += temp;


        }
        return ans;
    }
    TreeNode* helper(TreeNode* root, unordered_map<TreeNode* , TreeNode*>& mpp, int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node = q.front();
            if(node->val==start) res = node;
            if(node->left){
                mpp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mpp[node->right] = node;
                q.push(node->right);
            }
            q.pop();
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode* , TreeNode*> mpp;
        TreeNode* tar = helper(root, mpp, start);
        return helper2(root, mpp, tar);
    }
};
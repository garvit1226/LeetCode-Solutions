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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;

        int left = findleft(root);
        int right = findright(root);
        if(left==right) return (1<<left)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int findleft(TreeNode* node){
        int ans=0;
        while(node){
            ans++;
            node = node->left;
        }
        return ans;
    }
    int findright(TreeNode* node){
        int ans=0;
        while(node){
            ans++;
            node = node->right;
        }
        return ans;
    }
};
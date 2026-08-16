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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root = helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mpp);
        return root;
    }
    TreeNode* helper(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe,unordered_map<int, int>& mpp ){
        if(ps>pe || is>ie) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int inroot = mpp[postorder[pe]];
        int numsrem = inroot - is;
        root->left= helper(inorder, is, inroot-1, postorder, ps, ps+numsrem-1, mpp);
        root->right= helper(inorder, inroot+1, ie, postorder, ps+numsrem, pe-1, mpp);
        return root; 
    }
};
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;

        queue<TreeNode*> que;
        que.push(root);
        int flag =1;
        while(!que.empty()){
            int size = que.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();
                int idx = flag? i: size-1-i;
                row[idx] = node->val;
                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }

            }
            flag = flag? 0:1;
            res.push_back(row);
        }
        return res;
    }
};
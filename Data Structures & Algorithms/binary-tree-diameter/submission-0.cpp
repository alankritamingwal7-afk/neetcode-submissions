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
    int dia = 0;
    int dfs(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        //update the diameter
        dia = max(dia,left+right);

        return 1+max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return dia;
        
    }
};

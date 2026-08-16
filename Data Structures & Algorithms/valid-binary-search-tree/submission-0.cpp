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
    bool helper(TreeNode* root, long maxi, long mini){
        if(root==NULL){
            return true;
        }
        //if root value is out of range 
        if(root->val<=mini || root->val>=maxi){
         return false;  
        }
        return helper(root->left, root->val, mini) && 
       helper(root->right, maxi, root->val);


    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MAX,LONG_MIN);
        
    }
};

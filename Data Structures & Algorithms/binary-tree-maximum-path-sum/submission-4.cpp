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
int maxi = INT_MIN;
class Solution {
public:
    int maxi = INT_MIN;
    int maxsum(TreeNode* root){
        if(root==nullptr){
          return 0;  
        }
        // avoiding the negative numbers
        int left =max(0, maxsum(root->left));
        int right =max(0,maxsum(root->right));
        maxi = max(maxi, left+right+root->val);

        return max(left,right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        maxsum(root);
        return maxi;

    }
};

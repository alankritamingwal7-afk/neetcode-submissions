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
    TreeNode* maketree(vector<int>& pre, int ps,int pe,vector<int>& ino, int is, int ie,map<int,int>& mp){

        //boundary case
        if(ps>pe || is>ie){
            return nullptr;
        }

        //create a node root
        TreeNode* node = new TreeNode(pre[ps]);
        // get the index of node from inorder map
        int ind = mp[node->val];
        //calculate the # of elemnt 
        int nele = ind-is;

        // construct left side
        node->left = maketree(pre,ps+1,ps+nele,ino,is,ind-1,mp);
        node->right = maketree(pre,ps+nele+1,pe,ino,ind+1,ie,mp);
        return node;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pstart, pend, istart, iend;
        int n = preorder.size();
        pstart = 0;
        pend = n-1;
        istart = 0;
        iend = n-1;
        //creating map of value and index
        // where value --> key
        // key ---> index
        // only inorder is stored in map 

        map<int, int> mp;
        for(int i=0 ;i<n;i++){
            mp[inorder[i]]= i;
        }

        return maketree(preorder,pstart,pend,inorder,istart,iend,mp);
        
    }
};

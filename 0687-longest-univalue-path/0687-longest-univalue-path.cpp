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
    int DFS(TreeNode*root,int &max_len){
        if(!root)return max_len;
        int lh=DFS(root->left,max_len);
        int rh=DFS(root->right,max_len);
        if(!root->left || root->left->val!=root->val)lh=0;
        if(!root->right || root->right->val!=root->val)rh=0;
        max_len=max(max_len,lh+rh);
        return 1+max(lh,rh);

    }
    int longestUnivaluePath(TreeNode* root) {
        //path can start from any node & can have maximum value left height+right height where root->val==each value in that path like the case[5,5,5,5,1,null,5] 
        int res=INT_MIN;
        DFS(root,res);
        return res!=INT_MIN?res:0;
        
    }
};
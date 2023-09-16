class Solution {
private:
    void findRightSideView(TreeNode* node,vector<int> &ans){
        if(node==NULL) return;
        queue<pair<TreeNode*,int>> q;
        int curlvl=-1;
        q.push({node,0});
        while(!q.empty()){
            auto ele=q.front();
            q.pop();
            node=ele.first;
            int lvl=ele.second;
            if(curlvl<lvl){
                ans.push_back(node->val);
                curlvl=lvl;
            }
            if(node->right!=nullptr) q.push({node->right,lvl+1});
            if(node->left!=nullptr) q.push({node->left,lvl+1});
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        findRightSideView(root,ans);
        return ans;
        
        
    }
};
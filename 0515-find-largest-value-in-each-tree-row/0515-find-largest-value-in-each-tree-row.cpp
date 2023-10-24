class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL)return {};
        vector<int> ans;
        int mx,n;
        queue<TreeNode*> q;
        TreeNode* p;
        q.push(root);
        while(!q.empty()){
            n = q.size();
            mx = INT_MIN;
            while(n--){
                p = q.front();q.pop();
                mx = max(mx,p->val);
                if(p->left)q.push(p->left);
                if(p->right)q.push(p->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
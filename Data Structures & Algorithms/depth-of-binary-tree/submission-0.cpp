class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if(root == nullptr) return 0;
        queue <TreeNode*> q;
        q.emplace(root);
        while(!q.empty()){
            int levelsize = q.size();
            for(int i = 0;i<levelsize;i++){
                TreeNode* u = q.front();
                q.pop();
                if(u->left)q.emplace(u->left);
                if(u->right)q.emplace(u->right);
            }
            depth++;
        }    
        return depth;
    }
};
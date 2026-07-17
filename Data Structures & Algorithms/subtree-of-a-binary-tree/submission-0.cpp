class Solution {
   public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return false;
        if (subRoot == nullptr) return true;
        queue<TreeNode*> q1;
        q1.emplace(root);
        while (!q1.empty()) {
            bool isMatch = true;
            TreeNode* rootval = q1.front();
            q1.pop();
            if (subRoot->val == rootval->val) {
                queue<TreeNode*> q2;
                queue<TreeNode*> q3;
                q2.emplace(rootval);
                q3.emplace(subRoot);
                while (!q2.empty() && !q3.empty()) {
                    TreeNode* u1 = q2.front();
                    TreeNode* u2 = q3.front();
                    q2.pop();
                    q3.pop();
                    if (u1 == nullptr && u2 == nullptr) {
                        continue;
                    }
                    if (u1 == nullptr || u2 == nullptr) {
                        isMatch = false;
                        break;
                    }
                    if (u1->val != u2->val) {
                        isMatch = false;
                        break;
                    }
                    q2.emplace(u1->left);
                    q2.emplace(u1->right);
                    q3.emplace(u2->left);
                    q3.emplace(u2->right);
                }
                if(isMatch == true && q2.empty() && q3.empty()){
                    return true;
                }
            }
            if (rootval->left != nullptr) q1.emplace(rootval->left);
            if (rootval->right != nullptr) q1.emplace(rootval->right);
        }
        return false;
    }
};
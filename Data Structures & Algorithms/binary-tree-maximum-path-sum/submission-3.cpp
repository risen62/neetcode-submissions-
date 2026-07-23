class Solution {
public:
    int max_sum = INT_MIN;
    
    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int left_sum = max(0, dfs(root->left));    
        int right_sum = max(0, dfs(root->right));  
        
        int through_path = left_sum + root->val + right_sum;
        int return_path = root->val + max(left_sum, right_sum);
        
        max_sum = max(max_sum, through_path);
        return return_path;
    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_sum;
    }
};
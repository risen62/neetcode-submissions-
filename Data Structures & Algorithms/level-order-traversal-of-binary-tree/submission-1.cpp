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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr){
            return result;
        }
        queue <TreeNode*> q;
        q.emplace(root);
        while(!q.empty()){
            int levelsize = q.size();
            vector<int> levelvalues;
            for(int i = 0;i<levelsize;i++){
                TreeNode *current = q.front();
                levelvalues.push_back(current->val);
                q.pop();
                if(current->left != nullptr)q.emplace(current->left);
                if(current->right != nullptr)q.emplace(current->right);
            }   
            result.push_back(levelvalues);
        }  
        return result;
    }
};

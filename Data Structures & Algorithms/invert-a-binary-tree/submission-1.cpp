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
    TreeNode* invertTree(TreeNode* root) {
        if(root ==  nullptr){
            return nullptr;
        }
        queue <TreeNode*> q;
        q.emplace(root);
        while(!q.empty()){
            TreeNode *current = q.front();
            q.pop();
            swap(current->left,current->right);  
            if(current->left!=nullptr)q.emplace(current->left);
            if(current->right!=nullptr) q.emplace(current->right);
        }
        return root;  
    }
};

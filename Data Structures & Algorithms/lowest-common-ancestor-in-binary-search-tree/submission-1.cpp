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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *current = root;
        while((p->val > current->val && q->val > current->val || p->val < current->val && q->val < current->val )){
            if(p->val < current->val && q->val < current->val){
                current  = current->left;
            }
            if(p->val > current->val && q->val > current->val){
                current = current->right;
            }
        }
        return current;
    }
};

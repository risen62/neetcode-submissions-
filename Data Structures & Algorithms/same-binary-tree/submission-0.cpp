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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.emplace(p);
        q2.emplace(q);
        while (!q1.empty() && !q2.empty()) {
            TreeNode* current1 = q1.front();
            TreeNode* current2 = q2.front();
            q1.pop();
            q2.pop();
            if(current1 == nullptr && current2 == nullptr){
                continue;
            }
            if(current1 == nullptr || current2 == nullptr){
                return false;
            }
            if(current1->val !=  current2->val){
                return false;
            }

            q1.emplace(current1->left);
            q1.emplace(current1->right);

            q2.emplace(current2->left);
            q2.emplace(current2->right);
        }
        return q1.empty() && q2.empty();
    }
};

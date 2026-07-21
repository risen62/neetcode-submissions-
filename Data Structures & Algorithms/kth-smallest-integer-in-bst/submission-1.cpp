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
    int kthSmallest(TreeNode* root, int k) {
        stack <TreeNode*> s;
        vector<int> array;
        while(!s.empty() || root != nullptr){
            if(root != nullptr){
                s.push(root);
                root = root->left;
            }else{
                root = s.top();
                s.pop();
                array.push_back(root->val);
                if(array.size() == k) break;
                root = root->right;
            }
        } 
        return array[k - 1];
    }
};

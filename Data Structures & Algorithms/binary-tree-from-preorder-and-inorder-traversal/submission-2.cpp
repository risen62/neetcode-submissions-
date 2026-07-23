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
    int search(vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preorderindex, int left,
                     int right) {
        if (left > right) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[preorderindex]);
        int inorderindex = search(inorder,left, right, preorder[preorderindex]);
        preorderindex++;
        root->left = helper(preorder, inorder, preorderindex, left, inorderindex - 1);
        root->right = helper(preorder, inorder, preorderindex, inorderindex + 1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderindex = 0;
       return helper(preorder, inorder, preorderindex, 0, preorder.size() - 1);
    }
};

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

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "null";
        string serialize;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* current = s.top();
            s.pop();
            if (serialize.empty() == false) {
                serialize += ",";
            }
            if (current == nullptr) {
                serialize += "null";
            } else {
                serialize += to_string(current->val);
                s.push(current->right);
                s.push(current->left);
            }
        }
        return serialize;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> values;
        stringstream ss(data);
        string item;
        while (getline(ss, item, ',')) {
            values.push_back(item);
        }
        int indexpointer = 0;
        return helper(values, indexpointer);
    }
    TreeNode* helper(vector<string>& values, int& indexpointer) {
        if (values[indexpointer] == "null") {
            indexpointer++;
            return nullptr;
        }
        int node_data = stoi(values[indexpointer]);
        TreeNode* node = new TreeNode(node_data);
        indexpointer++;
        node->left = helper(values, indexpointer);
        node->right = helper(values, indexpointer);
        return node;
    }
};

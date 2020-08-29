/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode *> que;
        string res;
        que.emplace(root);
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            if (node) {
                res += to_string(node->val) + ",";
                que.emplace(node->left);
                que.emplace(node->right);
            }
            else {
                res += "nullptr,";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode *> que;
        stringstream s(data);
        string str_node;
        TreeNode *root;
        getline(s, str_node, ',');
        if (str_node == "nullptr") {
            root = nullptr;
            return root;
        }
        else {
            root = new TreeNode(stoi(str_node));
            que.emplace(root);
        }
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            if (node) {
                if (getline(s, str_node, ',') && str_node != "nullptr") {
                    TreeNode *temp = new TreeNode(stoi(str_node));
                    node->left = temp;
                    que.emplace(temp);
                }
                if (getline(s, str_node, ',') && str_node != "nullptr") {
                    TreeNode *temp = new TreeNode(stoi(str_node));
                    node->right = temp;
                    que.emplace(temp);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end


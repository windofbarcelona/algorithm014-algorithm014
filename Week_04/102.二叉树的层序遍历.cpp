/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return res;
        queue<TreeNode*> que;
        que.emplace(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> temp;
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                if (!node)
                    continue;
                temp.emplace_back(node->val);
                que.emplace(node->left);
                que.emplace(node->right);
            }
            if (!temp.empty())
                res.emplace_back(temp);
        }
        return res;
    }
private:
    vector<vector<int>> res;
};
// @lc code=end


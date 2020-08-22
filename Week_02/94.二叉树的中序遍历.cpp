/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
         if(!root)
            return res;
        buildRes(root);
        return res;
        
    }
    void buildRes(TreeNode *root) {
        if (!root)
            return;
        buildRes(root->left);
        res.emplace_back(root->val);
        buildRes(root->right);
    }
    vector<int> res;
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        return buildRes(root, LONG_MIN, LONG_MAX);
    }
    bool buildRes(TreeNode *node, long long low, long long upper) {
        if (!node)
            return true;
        if (node->val >= upper || node->val <= low)
            return false;
        //左右子树都是搜索树才ok
        return buildRes(node->left, low, node->val) && 
            buildRes(node->right, node->val, upper);
    }
};
// @lc code=end


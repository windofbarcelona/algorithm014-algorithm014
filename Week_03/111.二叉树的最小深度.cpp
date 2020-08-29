/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        /*
        BFS
        que.emplace(root, 1);
        while (!que.empty()) {
            TreeNode *node = que.front().first;
            int depth = que.front().second;
            que.pop();
            if (!node->left && !node->right) {
                return depth;
            }
            if (node->left)
                que.emplace(node->left, depth+1);
            if (node->right)
                que.emplace(node->right, depth+1);
        }
        return 0;
        */
       return buildRes(root);
    }
    int buildRes(TreeNode *root) {
        if (!root)
            return 0;
        if (root->left && root->right)
            return min(buildRes(root->left), buildRes(root->right)) + 1;
        else
            return max(buildRes(root->left), buildRes(root->right)) + 1;
    }
private:
    queue<pair<TreeNode *, int>> que;
};
// @lc code=end


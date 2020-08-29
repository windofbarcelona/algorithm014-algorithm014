/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = inorder.size();
        idx = 0;
        for (int i=0; i<n; i++)
            mp.insert(make_pair(inorder[i], i));
        return buildRes(preorder, 0, n-1);
    }
    TreeNode *buildRes(vector<int> &preorder, int left, int right) {
        if (left > right)
            return nullptr;
        int i = mp[preorder[idx]];
        TreeNode *root = new TreeNode(preorder[idx++]);
        root->left = buildRes(preorder, left, i-1);
        root->right = buildRes(preorder, i+1, right);
        return root;
    }
private:
    int idx, n;
    unordered_map<int, int> mp;
};
// @lc code=end


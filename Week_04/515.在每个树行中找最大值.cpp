/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */

// @lc code=start
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
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return res;
        queue<TreeNode*> que;
        que.emplace(root);
        while (!que.empty()) {
            int size = que.size();
            int max = INT_MIN;
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                if (!node)
                    continue;
                max = node->val>max?node->val:max;
                que.emplace(node->left);
                que.emplace(node->right);
            }
            if (!que.empty())
                res.emplace_back(max);
        }
        return res;
        /*
        buildTemp(root, 0);
        buildRes();
        return res;
        */
    }
    void buildTemp(TreeNode* root, int level) {
        if (!root)
            return;
        if (level >= temp.size())
            temp.emplace_back(vector<int>());
        temp[level].emplace_back(root->val);
        buildTemp(root->left, level+1);
        buildTemp(root->right, level+1);
    }
    void buildRes() {
        //在102基础上，找出每一层的最大值
        int size = temp.size();
        for (int i=0; i<size; i++) {
            int max = INT_MIN;
            for (int j=0; j<temp[i].size(); j++) {
                max = temp[i][j] > max?temp[i][j]:max;
            }
            res.emplace_back(max);
        }
    }
private:
    vector<vector<int>> temp;
    vector<int> res;
};
// @lc code=end


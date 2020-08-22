/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        buildRes(root, 0);
        return res;
    }
    void buildRes(Node *root, int level) {
        if (!root)
            return;
        if (level >= res.size())
            res.emplace_back(vector<int>());
        res[level].emplace_back(root->val);
        auto child = root->children;
        for (int i=0;i<child.size(); i++) 
            buildRes(child[i], level+1);
    }
private:
    vector<vector<int>> res;
    queue<Node *> que;
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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

/*
解题思路：
两个节点 p,q 分为两种情况：

p 和 q 在相同子树中
p 和 q 在不同子树中
从根节点遍历，递归向左右子树查询节点信息
递归终止条件：如果当前节点为空或等于 p 或 q，则返回当前节点

递归遍历左右子树，如果左右子树查到节点都不为空，则表明 p 和 q 分别在左右子树中，因此，当前节点即为最近公共祖先；
如果左右子树其中一个不为空，则返回非空节点。

作者：guohaoding
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/236-er-cha-shu-de-zui-jin-gong-gong-zu-xian-jian-j/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        if (!root || root == p || root == q) //这个退出条件太强了
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        return left ? left : right;
        */
       fa[root->val] = nullptr;
       buildRes(root);
       while (p) {
           path[p->val] = true;
           p = fa[p->val];
       }
       while (q) {
            if (path[q->val])
                return q;
            q = fa[q->val];
       }
       return nullptr;
    }
    void buildRes(TreeNode *root) {
        stack<TreeNode *> st;
        if (root)
            st.emplace(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            if (node) {
                if (node->right) {
                    fa[node->right->val] = node;
                    st.emplace(node->right);
                }
                if (node->left) {
                    fa[node->left->val] = node;
                    st.emplace(node->left);
                }
            }
        }

    }
    unordered_map<int, TreeNode *> fa;
    unordered_map<int, bool> path;
};
// @lc code=end


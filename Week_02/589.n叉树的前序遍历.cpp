/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
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
    vector<int> preorder(Node* root) {
        if (!root)
            return res;
        st.emplace(root);
        while (!st.empty()) {
            Node *node = st.top();
            st.pop();
            if (node) {
                res.emplace_back(node->val);
                if(!node->children.empty())
                    for (int i=node->children.size()-1; i>=0; i--)
                        st.emplace(node->children[i]);
            }
            else 
                continue;
        }
        return res;
    }
private:
    vector<int> res;
    stack<Node *> st;
};
// @lc code=end


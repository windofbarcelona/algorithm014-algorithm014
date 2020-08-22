/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
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
    vector<int> postorder(Node* root) {
        if (!root)
            return res;
        st.emplace(root);
        while (!st.empty()) {
            Node *node = st.top();
            st.pop();
            if (node) {
                st.emplace(node);
                st.emplace(nullptr);
                if (!node->children.empty()) {
                    auto child = node->children;
                    for (int i = child.size(); i>=0;i--)
                        st.emplace(childe[i]);
                }
            }
            else {
                res.emplace_back(st.top()->val);
                st.pop();
            }
        }
        return res;
    }
private:
    stack<Node *> st;
    vector<int> res;
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        /*
        //DFS非递归
        vector<string> res;
        stack<my_pair> st;
        lr lr_1(0, 0);
        my_pair my_pair_1("", lr_1);
        st.emplace(my_pair_1);
        while (!st.empty()) {
            auto top = st.top();
            st.pop();
            string str = top.first;
            int left = top.second.first;
            int right = top.second.second;
            if (left == n && right == n)
                res.emplace_back(str);
            if (left < n) {
                lr lr_1(left+1, right);
                my_pair my_pair_1(str+"(", lr_1);
                st.emplace(my_pair_1);
            }
            if (right < left) {
                lr lr_1(left, right+1);
                my_pair my_pair_1(str+")", lr_1);
                st.emplace(my_pair_1);
            }
                
        }
        */
        
        //BFS
        vector<string> res;
        queue<pair<string, pair<int, int>>>q; // pair<当前的括号, pair<左括号剩余, 右括号剩余>>
        q.push({"",{n,n}});
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            string str = top.first;
            int left = top.second.first;
            int right = top.second.second;
            if (left == 0 && right == 0) {
                res.push_back(str);
            }
            if (left > 0) {
                q.push({str + '(',{left-1,right}});
            }
            if (right > 0 && right > left) {
                q.push({str + ')',{left,right-1}});
            }
        }
        
        //buildRes(0, 0, n, "");
        return res;
    }
    //DFS 递归写法
    void buildRes(int left, int right, int count, string temp) {
        if (left == count && right == count)
            res.emplace_back(temp);
        if (left < count)
            buildRes(left+1, right, count, temp+"(");
        if (right < left)
            buildRes(left, right+1, count, temp+")");
    }
private:
    vector<string> res;
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        buildRes(0, 0, n, "");
        return res;
    }
    
    void buildRes(int left, int right, int count, string str) {
        //跳出条件
        if (left == count && right == count) {
            res.emplace_back(str);
            return;
        }
        //处理当前逻辑 并进入下一层
        if (left < count)
            buildRes(left+1, right, count, str+"(");
        if (right < left)
            buildRes(left, right+1, count, str+")");
    }   

private:
    vector<string> res;
};
// @lc code=end


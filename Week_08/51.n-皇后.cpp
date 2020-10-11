/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n < 0)
            return res;
        size = (1 << n) - 1;
        vector<string> nQueens(n, string(n, '.'));
        dfs(nQueens, n, 0, 0, 0, 0);
        return res;
    }
    void dfs(vector<string>& nQueens, int n, int row, int col, int pie, int na) {
        if (row >= n) {
            res.emplace_back(nQueens);
            return;
        }
        int bits = size & (~(col | pie | na));
        while (bits != 0) {
            int bit = bits & (-bits);
            bits &= (bits - 1);
            nQueens[row][log2(bit)] = 'Q';
            dfs(nQueens, n, row+1, col | bit, (pie | bit) << 1, (na | bit) >> 1);
            nQueens[row][log2(bit)] = '.';
        }
    }
private:
    vector<vector<string>> res;
    int size;
};
// @lc code=end


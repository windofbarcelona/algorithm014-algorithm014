/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        res = 0;
        dfs(n, 0, 0, 0, 0);
        return res;
    }
    void dfs(int n, int row, int col, int pie, int na) {
        while (row >= n) {
            res++;
            return;
        }
        int bits = ~(col | pie | na) & ((1 << n) - 1);
        while (bits > 0) {
            int p = bits & -bits;
            dfs(n, row+1, col | p, (pie | p) << 1, (na | p) >> 1);
            bits &= bits - 1; 
        }
    }
private:
    int res;
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
// f(n) = f(n-1) + f(n-2)
class Solution {
public:
    int climbStairs(int n) {
        
        if (n < 3)
            return n;
        int a = 1, b = 2, c = 3;
        for (int i = 3; i <= n; i++) {
            c = b + a;
            a = b;
            b = c;
        }
        return c;
    }
};
// @lc code=end


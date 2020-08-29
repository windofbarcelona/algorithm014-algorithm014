/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        long long N = n;
        return n>0?quickMul(x,N):1.0/quickMul(x, -N);
    }
    double quickMul(double x, long long n) {
        //最小子问题，即为跳出条件
        if (n == 1)
            return x;
        //继续拆分
        double res = quickMul(x, n/2);
        //合并子问题反馈上来的结果
        return n%2==0?res*res:res*res*x;
    }
};
// @lc code=end


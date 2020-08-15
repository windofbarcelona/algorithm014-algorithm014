/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
//走过来等于从 n-1级走过来 或者从  n-2级走过来
    int climbStairs(int n) {
        if(n<3)
            return n;
        int a=1,b=2,c=3;
        for(int i=3;i<n+1;i++)
        {
            c = a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
// @lc code=end


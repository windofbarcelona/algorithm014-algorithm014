/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // n & 1 得到最后一位
        // n & (n-1)最后一位1清零
        // n & (-n) 得到最后一位1
        uint32_t res = 0, left = 31;
        while (n != 0) {
            res += (n & 1) << left--;
            n = n >> 1;
        }
        return res;
    }
};
// @lc code=end


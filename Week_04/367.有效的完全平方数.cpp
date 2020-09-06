/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 1, right = num;
        long mid = 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (mid * mid == num)
                return true;
            else if (mid * mid < num)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return false;
    }
};
// @lc code=end


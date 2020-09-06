// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem69.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        long left = 1, right = x;
        long mid = 1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                left = mid + 1;
            }
            else 
                right = mid - 1;
        }
        return ans;
    }
};
// @lc code=end


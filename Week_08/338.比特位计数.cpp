/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {
        dp = vector<int>(num + 1, 0);
        for (int i=1; i<num+1; i++) {
            dp[i] = dp[i & (i-1)] + 1;
        }
        return dp;
    }
private:
    vector<int> dp;
};
// @lc code=end


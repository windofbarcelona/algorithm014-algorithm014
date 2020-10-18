/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        //dp[i] = dp[i - 2] + 2
        //dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2]
        int size = s.length();
        if (0 == size)
            return 0;
        vector<int> dp(size, 0);
        for (int i = 1; i < size; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = 2;
                    if (i - 2 > 0)
                        dp[i] += dp[i - 2];
                }
                //要求s[i - 1]s[i−1]位置必然是有效的括号对
                else if (dp[i - 1] > 0) {
                    if ((i - dp[i - 1] - 1) >= 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if (i - dp[i - 1] - 2 > 0)
                            dp[i] += dp[i - dp[i - 1] - 2];
                    }
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end


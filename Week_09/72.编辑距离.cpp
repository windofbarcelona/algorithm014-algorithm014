/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int size_1 = word1.size(), size_2 = word2.size();
        int dp[size_1 + 1][size_2 + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < size_1 + 1; i ++)
            dp[i][0] = dp[i - 1][0] + 1;
        for (int i = 1; i < size_2 + 1; i++)
            dp[0][i] = dp[0][i - 1] + 1;
        for (int i = 1; i < size_1 + 1; i++) {
            for (int j = 1; j < size_2 + 1; j++) {
                if (word1[i - 1]== word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
        return dp[size_1][size_2];
    }
};
// @lc code=end


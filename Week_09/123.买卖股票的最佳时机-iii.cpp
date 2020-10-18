/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i])
        //dp[i][k][0] = max(dp[i - 1][k][0], dp[i -1][k][1] + prices[i])
        int size = prices.size();
        if (0 == size)
            return 0;
        int max_k = 2;
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(max_k + 1, vector<int>(2, 0)));
        dp[0][1][0] = 0;
        dp[0][1][1] = -prices[0];
        dp[0][2][0] = 0;
        dp[0][2][1] = -prices[0];
        for (int i = 1; i < size; i++) {
            for (int k = 1; k <= max_k; k++) {
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i -1][k][1] + prices[i]);
            }
        }
        return dp[size - 1][max_k][0];
    }
};
// @lc code=end


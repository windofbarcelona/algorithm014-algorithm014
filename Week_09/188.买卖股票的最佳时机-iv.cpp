/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i])
        //dp[i][k][0] = max(dp[i - 1][k][0], dp[i -1][k][1] + prices[i])
        int size = prices.size();
        if (0 == size)
            return 0;
        if (k >= size / 2)
            return maxProfit_inf(prices);
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        for (int i = 1; i <= k; i++) {
            dp[0][i][0] = 0;
            dp[0][i][1] = -prices[0];
        }
        for (int i = 1; i < size; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[size - 1][k][0];
    }
    int maxProfit_inf(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < size; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[size - 1][0];
    }
};
// @lc code=end


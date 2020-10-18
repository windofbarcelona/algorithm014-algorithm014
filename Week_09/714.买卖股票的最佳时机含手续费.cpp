/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
        //dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee)
        int size = prices.size();
        if (0 == size)
            return 0;
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for (int i = 0; i < size; i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i] - fee);
        }
        return dp_i_0;
    }
};
// @lc code=end


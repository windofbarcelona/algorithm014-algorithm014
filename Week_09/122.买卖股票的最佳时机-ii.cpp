/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i])
        //dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i])
        //因为不限制交易次数，所以k不会影响整个方程，所以k可以取消掉
        //dp[0][0] = 0; dp[0][1] = dp[-1][1] - prices[0]
        int size = prices.size();
        if (0 == size)
            return 0;
        int dp_i_0 = 0, dp_i_1 = -prices[0];
        for (int i = 1; i < size; i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }
};
// @lc code=end


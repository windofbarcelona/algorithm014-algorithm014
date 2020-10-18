/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
        //dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i])
        //dp[-1][0] = 0, dp[-1][1] = INT_MIN
        //在开始今天的交易之前，先记住昨天的未持有股票的状态，
        //交易结束后赋个dp_2_0,然后开始明天的交易，此时dp_2_0的值为前天的状态
        int size = prices.size();
        if (0 == size)
            return 0;
        int dp_i_0 = 0, dp_i_1 = INT_MIN, dp_2_0 = 0;
        for (int i = 0; i < size; i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, dp_2_0 - prices[i]);
            dp_2_0 = temp;
        }
        return dp_i_0;
    }
};
// @lc code=end


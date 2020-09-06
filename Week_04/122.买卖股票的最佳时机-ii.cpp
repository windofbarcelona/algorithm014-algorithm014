/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (int i=1; i<prices.size(); i++) {
            if (prices[i] > prices[i-1])
                maxProfit += prices[i] - prices[i-1];
        }
        return maxProfit;
    }
};
// @lc code=end


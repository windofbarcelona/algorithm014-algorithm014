/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
        dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i]) 
                    = max(dp[i-1][1][1], -prices[i])
        解释：k = 0 的 base case，所以 dp[i-1][0][0] = 0。

        现在发现 k 都是 1，不会改变，即 k 对状态转移已经没有影响了。
        可以进行进一步化简去掉所有 k：
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
        dp[i][1] = max(dp[i-1][1], -prices[i])
        */
        int size = prices.size();
        if (size == 0)
            return 0;
        //vector<vector<int>>dp (size, vector<int>(2, 0));
        //dp[0][0] = 0;
        //dp[0][1] = -prices[0];
        int dp_i_0 = 0;
        int dp_i_1 = -prices[0];
        for (int i = 1; i < size; i++) {
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, - prices[i]);
        }
        return dp_i_0;
        /*
        //维护一个递增栈
        int res = 0;
        vector<int> st;
        prices.emplace_back(-1);
        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && st.back() > prices[i]) {
                res = max(res, st.back() - st.front());
                st.pop_back();
            }
            st.emplace_back(prices[i]);
        }
        return res;
        */

        /*
        //双指针法
        int res = 0, temp = 0, slow = 0;
        int fast = slow + 1, size = prices.size();
        while (slow < size && fast < size) {
            if (prices[slow] < prices[fast])
                temp = prices[fast] - prices[slow];
            else
                slow = fast;
            fast++;
            res = max(res, temp);
        }
        return res;
        */
    }
};
// @lc code=end


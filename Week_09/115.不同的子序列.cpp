/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int s_size = s.size(), t_size = t.size();
    vector<vector<long>> dp(t_size + 1, vector<long>(s_size + 1, 0));
    fill(dp[0].begin(), dp[0].end(), 1);
    for (int i = 0; i < t_size; ++i) {
        for (int j = 0; j < s_size; ++j) {
            if (t[i] == s[j]) dp[i+1][j+1] = dp[i+1][j] + dp[i][j];
            else dp[i+1][j+1] = dp[i+1][j]; 
        }
    }
    return dp[t_size][s_size];
    }
};
// @lc code=end


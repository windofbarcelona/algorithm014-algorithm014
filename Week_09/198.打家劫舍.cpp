/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        //dp[n] = max(dp[n - 1] , nums[n] + dp[n - 2])
        //vector<int> dp(nums.size(), 0);
        //dp[0] = nums[0];
        //dp[1] = max(nums[0], nums[1]);
        int a = nums[0];
        int b = max(nums[0], nums[1]);
        int res = max(b, a);
        for (int i = 2; i < nums.size(); i++) {
            //dp[i] = max(dp[i - 1] , nums[i] + dp[i - 2]);
            res = max(b, nums[i] + a);
            a = b;
            b = res;
        }
            
        return res;
    }
};
// @lc code=end


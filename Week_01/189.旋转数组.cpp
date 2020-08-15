/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        k = k% length;
        reverse(nums.begin(), nums.end());
        reverse(&nums[0], &nums[k]);
        reverse(&nums[k], &nums[length]);
    }
};
// @lc code=end


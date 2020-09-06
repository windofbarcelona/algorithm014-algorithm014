/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        //最后ledft和right会重合，然后退出循环
        while (left < right) {
            int mid = left + (right - left) / 2;
            //左边有序 去右边找
            if (nums[mid] > nums[right]) {          
                left = mid + 1;
            } else {                               
                right = mid;
            }
        }
        return nums[left];
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int p1 = 0, p2 = nums.size() - 1;
        int mid = p1;
        while(p1 <= p2)
        {
            mid = (p1 + p2) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] >= nums[p1]) // 说明[p1,mid]区间是有序的
            {
                // 因为[p1,mid]区间是有序的，所以通过p1和mid处的值就能判断target在不在区间内
                if(nums[p1] <= target && target < nums[mid]) p2 = mid - 1;
                else p1 = mid + 1; // 如果不在，就去[mid+1,p2]区间找target
            }
            else // 说明[mid,p2]区间是有序的
            {
                // 因为[mid,p2]区间是有序的，所以通过mid和p2处的值就能判断target在不在区间内
                if(nums[mid] < target && target <= nums[p2]) p1 = mid + 1;
                else p2 = mid - 1; // 如果不在，就去[p1,mid-1]区间找target
            }
        }
        return -1;
        /*
        //先找到旋转点，然后在旋转点的左右两边进行查找
        int fenjiedian = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i>0 && nums[i] > nums[i-1])
                fenjiedian = i;
            else if (i > 0 && nums[i] < nums[i-1])
                break;
        }
        int left = buildRes(nums, 0, fenjiedian, target);
        int right = buildRes(nums, fenjiedian+1, nums.size()-1, target);
        return  left==-1?right:left;
        */
    }
    int buildRes(vector<int>& nums, int start, int end, int target) {
        int res = -1;
        long left = start, right = end, mid = 0;
        while (left <= right) {
            mid = (left+right)/2;
            if (nums[mid] == target) 
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else 
                right = mid - 1;
        }

        return res;
    }
};
// @lc code=end


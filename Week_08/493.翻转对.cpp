/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        res = 0;
        temp = vector<int>(nums.size(), 0);
        mergeSort(nums, 0, nums.size() - 1);
        return res;
    }
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        int i = left, j = mid + 1, k = left;
        //统计翻转对的个数
        while (i <= mid && j <= right) {
            long long l = nums[i], r = nums[j];
            r *= 2;
            if (l > r) {
                j++;
                res += mid - i + 1;
            }
            else
                i++;
        }
        //正常merge
        i = left, j = mid + 1;
        while (i <= mid && j <= right) 
            temp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
        while (i <= mid)
            temp[k++] = nums[i++];
        while (j <= right)
            temp[k++] = nums[j++];
        copy(temp.begin() + left, temp.begin() + right + 1, nums.begin() + left);
    }
private:
    int res;
    vector<int> temp;
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> track;
        vector<bool> used (nums.size(), false);
        sort(nums.begin(), nums.end());
        buildRes(nums, used, track);
        return res;
    }
    void buildRes(vector<int>& nums, vector<bool>& used, vector<int>& track) {
        if (nums.size() == track.size()) {
            res.emplace_back(track);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            //不能选自己 || 回溯到了同一层
            if (used[i] || (i > 0 && !used[i-1] && nums[i] == nums[i-1]))
                continue;
            //在当前层进行选择
            track.emplace_back(nums[i]);
            used[i] = true;
            //进入下一层
            buildRes(nums, used, track);
            //撤销选择
            used[i] = false;
            track.pop_back();
        }
    }
private:
    vector<vector<int>> res;
};
// @lc code=end


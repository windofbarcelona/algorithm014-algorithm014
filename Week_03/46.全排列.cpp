/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    /*
    result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择

作者：labuladong
链接：https://leetcode-cn.com/problems/combinations/solution/hui-su-si-xiang-tuan-mie-pai-lie-zu-he-zi-ji-wen-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    
    */

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        buildRes(nums, track);
        return res;
    }
    void buildRes(vector<int>& nums, vector<int>& track) {
        //跳出条件
        if (track.size() == nums.size()) {
            res.emplace_back(track);
            return;
        }
        for (int i=0;i<nums.size();i++) {
            //剪枝条件，因为nums中数字不重复，且结果不重复，所以不能自己选自己，与used数据效果一致
            if (find(track.begin(), track.end(), nums[i]) != track.end())
                continue;
            //选择
            track.emplace_back(nums[i]);
            //进入下一层
            buildRes(nums, track);
            //撤销选择
            track.pop_back();
        }
    }
private:
    vector<vector<int>> res;
};
// @lc code=end


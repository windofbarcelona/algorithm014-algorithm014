  /*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
        // base case，返回一个空集
        if (nums.empty()) return {{}};
        // 把最后一个元素拿出来
        int n = nums.back();
        nums.pop_back();
        // 先递归算出前面元素的所有子集
        vector<vector<int>> res = subsets(nums);

        int size = res.size();
        for (int i = 0; i < size; i++) {
            // 然后在之前的结果之上追加
            res.push_back(res[i]);
            res.back().push_back(n);
        }
        return res;
        */
       vector<int> track;
       backtrack(nums, 0, track);
       return res;
    }
    void backtrack(vector<int> &nums, int start, vector<int>& track) {
        res.emplace_back(track);
        for (int i=start; i<nums.size(); i++) {
            track.emplace_back(nums[i]);
            backtrack(nums, i+1, track);
            track.pop_back();
        }
    }
private:
    vector<vector<int>> res;
};
// @lc code=end


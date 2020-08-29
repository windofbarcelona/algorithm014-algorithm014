/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> track;
        buildRes(n, k, 1, track);
        return res; 
    }
    void buildRes(int n, int k, int start, vector<int>& track) {
        if (track.size() == k) {
            //递归结束条件,只有当满足条件时才加入结果集
            res.emplace_back(track);
            return;
        }
        //剪枝条件，如果i<=n相当于是不剪枝，也能得出结果，但是效率很差
        for (int i=start; i<=n - (k-track.size()) + 1; i++) {
            track.emplace_back(i);
            buildRes(n, k, i+1, track);
            track.pop_back();
        }
    }
private:
    vector<vector<int>> res;
};
// @lc code=end


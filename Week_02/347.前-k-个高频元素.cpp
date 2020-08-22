/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int i=0; i<nums.size(); i++)
            count[nums[i]]++;
        for (auto num : count) {
            que.push({num.second, num.first});
            if (que.size() > k)
                que.pop();
        }
        while (!que.empty()) {
            res.emplace_back(que.top().second);
            que.pop();
        }
        return res;
    }
private:
    vector<int> res;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
    greater<pair<int, int>>> que;
};
// @lc code=end


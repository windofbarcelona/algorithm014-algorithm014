/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // 347题的解法 
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
            less<pair<int, int>>> que;
        for (auto num : nums) 
            mp[num]++;
        for (auto num : mp)
            que.push({num.second, num.first});
        return que.top().second;
    }
};
// @lc code=end


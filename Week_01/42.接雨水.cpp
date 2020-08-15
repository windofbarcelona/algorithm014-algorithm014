/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (0 == height.size())
            return 0;
        int size = height.size();
        int water = 0;
        for (int i=0;i<size;i++) {
            while(!stac.empty() && height[stac.top()] < height[i]) {
                int cur = stac.top();
                stac.pop();
                if (stac.empty())
                    break;
                int left = stac.top();
                int right = i;
                int h = min(height[right], height[left]) - height[cur];
                water += (right - left - 1) * h;
            }
            stac.emplace(i);
        }
        return water;
    }
private:
    stack<int> stac;
};
// @lc code=end


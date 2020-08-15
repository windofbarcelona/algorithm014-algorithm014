// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem84.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       heights.emplace_back(0);
       int len = heights.size(), maxarea = 0;
       stack<int> stac;
       for (int i=0; i<len; i++) {
           while (!stac.empty() && heights[i] < heights[stac.top()]) {
                int cur = stac.top();
                stac.pop();
                if (stac.empty())
                    maxarea = max(maxarea, (heights[cur] * i));
                else
                    maxarea = max(maxarea, heights[cur] * (i-stac.top()-1));
           }
           stac.emplace(i);
       }
       return maxarea;
    }
};

// @lc code=end


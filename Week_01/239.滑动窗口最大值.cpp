/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class MonitorDeque {
private:
    deque<int> data;
public:
    void push(int a) {
        while (!data.empty() && data.back()<a)
            data.pop_back();
        data.push_back(a);
    }
    int max() {return data.front();}
    void pop(int a) {
        if (!data.empty() && data.front() == a)
            data.pop_front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonitorDeque window;
        vector<int> res;
        for (int i=0;i<nums.size();i++) {
            if (i < k-1)
                window.push(nums[i]);
            else {
                window.push(nums[i]);
                res.push_back(window.max());
                window.pop(nums[i-k+1]);
            }
        }
        return res;
    }
};
// @lc code=end


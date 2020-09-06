/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int size_g = g.size();
        int size_s = s.size();
        int res = 0;
        int i=0, j=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (i<size_g && j<size_s) {
            //胃口小于等于饼干大小
            if (g[i] <= s[j]) {
                res++;
                i++;
                j++;
            }
            else
                j++;
        }
        return res;
    }
};
// @lc code=end


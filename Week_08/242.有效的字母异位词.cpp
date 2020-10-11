/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int temp[26];
        memset(temp, 0, sizeof(temp));
        for (auto a : s)
            temp[a-'a']++;
        for (auto a : t)
            temp[a-'a']--;
        for (auto a : temp) 
            if (a != 0)
                return false;
        return true;
    }
};
// @lc code=end


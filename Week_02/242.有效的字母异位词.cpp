/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int temp[26]{0};
        bool flag = true;
        for (auto a:s) {
            temp[a - 'a']++;
        }
        for (auto a:t) {
            temp[a - 'a']--;
        }
        for (int i = 0; i < 26 ;i++) {
            if (temp[i] != 0) {
                flag = false;
                break;
            }
        }
        return flag;
        /*
        map<char, int> m; 
        for (auto a:s) {
            auto iter = m.find(a);
            if (iter != m.end()) {
                iter->second++;
            }
            else {
                m.insert(make_pair(a, 1));
            }
        }
        for (auto a:t){
            auto iter = m.find(a);
            if (iter != m.end()) {
                iter->second--;
                if (iter->second == 0)
                    m.erase(iter);
            }
            else 
                return false;
        }
        if (m.size() != 0)
            return false;
        else
            return true;
        */
    }
};
// @lc code=end


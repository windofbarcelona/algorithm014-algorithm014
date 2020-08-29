/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return res;
        string temp = "";
        int idx = 0;
        unordered_map<char, string> mp;
        mp.insert({'2', "abc"});
        mp.insert({'3', "def"});
        mp.insert({'4', "ghi"});
        mp.insert({'5', "jkl"});
        mp.insert({'6', "mno"});
        mp.insert({'7', "pqrs"});
        mp.insert({'8', "tuv"});
        mp.insert({'9', "wxyz"});
        buildRes(digits, temp, mp, idx);
        return res;
    }
    void buildRes(string& digits, string& temp, unordered_map<char, string>& mp, int idx) {
        //跳出条件
        if (temp.size() == digits.size()) {
            res.emplace_back(temp);
            return;
        }
        //处理当前层
        string letter = mp[digits[idx++]];
        for (int i=0; i<letter.size(); i++) {
            string temp_copy = temp+letter[i];
            //进入下一层
            buildRes(digits, temp_copy, mp, idx);
        }
    }
private:
    vector<string> res;
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change_05 = 0, change_10 = 0;
        for (auto bill : bills) {
            if (bill == 5)
                change_05++;
            else if (bill == 10) {
                change_05--;
                change_10++;
            }
            else {
                if (change_10 > 0) {
                    change_10--;
                    change_05--;
                }
                else 
                    change_05 -= 3;
            }
            if (change_05 < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end


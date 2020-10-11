/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> temp(1001, 0);
        for (auto i : arr1)
            temp[i]++;
        for (auto i : arr2)
            temp[i] *= -1;
        int cur = 0;
        //若temp[i]<0表示是在arr2中出现过的
        for (int i=0; i<arr2.size(); i++) {
            while (temp[arr2[i]] < 0) {
                arr1[cur++] = arr2[i];
                temp[arr2[i]]++;
            }
        }
        //若temp[i]>0表示是没有在arr2中出现过的
        for (int i=0; i<temp.size(); i++) {
            while (temp[i] > 0) {
                arr1[cur++] = i;
                temp[i]--;
            }
        }
        return arr1;
    }
};
// @lc code=end


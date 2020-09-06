/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int rowSize = matrix.size(), columnSize = matrix[0].size();
        int row = 0, column = columnSize - 1;
        while(row < rowSize && column >= 0)
        {
            // 从矩阵的右上角开始匹配，如果匹配到了，返回true
            if(matrix[row][column] == target) return true;
            // 如果值比target大，说明这一列都比target大，column往左移一行
            else if(matrix[row][column] > target) column --;
            // 如果值比target小，则说明这一行都比target小，row往下移一行
            else row ++;
        }
        return false;
    }
};
// @lc code=end


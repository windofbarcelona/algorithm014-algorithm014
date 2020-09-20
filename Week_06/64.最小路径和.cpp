/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int dp[m][n];
        dp[0][0]=grid[0][0];
        //下面两个部分的初始化利用了题目所说每次只能向下或者向右移动一步这个条件
        for(int i=1;i<m;i++)
           dp[i][0]=dp[i-1][0]+grid[i][0];
        for(int j=1;j<n;j++)
           dp[0][j]=dp[0][j-1]+grid[0][j];
        for(int i=0;i<m-1;i++)
           for(int j=0;j<n-1;j++){
               dp[i+1][j+1]=min(dp[i+1][j],dp[i][j+1])+grid[i+1][j+1];
               //到达dp[i][j]=到达dp[i][j-1],dp[i-1][j]两者中的较小部分+grid[i][j]
           }
        return dp[m-1][n-1];
    }
};
// @lc code=end


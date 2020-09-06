/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) 
	{
		int k = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > k) return false;  //如果当前位置超过了你能到达的最远位置，返回false
			k = max(k, i + nums[i]);
			if(k>=nums.size()-1)
				break;
		}
		return true;
	}

};
// @lc code=end


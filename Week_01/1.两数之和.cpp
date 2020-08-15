/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> myMap;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(myMap.find(target - nums[i])!= myMap.end())
            {
                res.emplace_back(myMap[target - nums[i]]);
                res.emplace_back(i);
                break;
            }
            myMap.insert(make_pair(nums[i],i));
        }
        return res;
    }
};
// @lc code=end


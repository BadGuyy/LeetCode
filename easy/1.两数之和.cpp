/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 哈希表解法，key为元素值，value为元素下标
        // 时间复杂度O(n)，空间复杂度O(n)
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(hashMap.find(target - nums[i]) != hashMap.end())
            {
                return vector<int> {hashMap[target - nums[i]], i};
            }
            else
            {
                hashMap[nums[i]] = i;
            }
        }
        
        // 暴力解法
        // 时间复杂度O(n^2)，空间复杂度O(1)
        // for(int i = 0; i < nums.size(); ++i)
        // {
        //     for(int j = i + 1; j < nums.size(); ++j)
        //     {
        //         if(nums[i] + nums[j] == target)
        //         {   
        //             return vector<int> {i, j};
        //         }
        //     }
        // }


        // 未找到解
        return {};
    }
};
// @lc code=end

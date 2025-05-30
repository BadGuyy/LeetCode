/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s)
    {
        // 动态规划
        // 时间复杂度O(n^2)，空间复杂度O(n^2)
        int len = s.size();
        if (len < 2) return s;
        // 定义dp数组，dp[i][j]表示s[i...j]是否为回文串
        // 这里双数组的上三角应该都为false，真正有意义的是下三角
        // 因为只需要判断i<=j的子串是否为回文串，下面的大循环已经排除了i>j的子串
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        // 记录最长回文子串的起始位置和长度
        int begin = 0, maxLen = 1;
        // 初始化边界条件，长度为1的子串都是回文串
        for(int i = 0; i < len; i++) dp[i][i] = true;
        // 枚举子串长度
        for(int subLen = 2; subLen <= len; subLen++)
        {
            // 枚举左边界
            for(int left = 0; left <= len - subLen; left++)
            {
                // 枚举右边界
                int right = left + subLen - 1;
                if(s[left] != s[right])
                    dp[left][right] = false;
                else if(subLen <= 3)
                    // 左右边界相同时，长度小于等于3的子串都是回文串
                    dp[left][right] = true;
                else
                    dp[left][right] = dp[left + 1][right - 1];

                // 更新最长回文子串
                if(dp[left][right] == true && subLen > maxLen)
                {
                    begin = left;
                    maxLen = subLen;
                }
            }
        }

        return s.substr(begin, maxLen);
    }
};
// @lc code=end


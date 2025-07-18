/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        int rev = 0;
        while (x!= 0)
        {
            if (rev < INT_MIN / 10 || rev > INT_MAX / 10)
            {
                return 0;
            }
            
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }

        return rev;
    }
};
// @lc code=end

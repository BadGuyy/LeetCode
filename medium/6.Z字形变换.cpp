/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.size())
        {
            return s;
        }

        string res = "";
        int columnGap = 2 * (numRows - 1);
        int zGap = 2 * (numRows - 1);
        for(int row = 0; row < numRows; row++)
        {
            int column = row;
            while(column < s.size())
            {
                res += s[column];
                if((row != 0 && row != numRows - 1) &&
                    zGap > 0 && column + zGap < s.size())
                {
                    res += s[column + zGap];
                }

                column += columnGap;
            }
            zGap -= 2;
        }

        return res;
    }
};
// @lc code=end

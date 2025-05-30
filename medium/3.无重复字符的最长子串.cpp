/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        // 滑动窗口法最终优化，不让左指针遍历到字符串末尾，使用数组记录上一次出现的位置
        // 时间复杂度 O(n)，空间复杂度 O(min(m, n))，m 为字符集大小，n 为字符串长度
        vector<int> last_index(128, -1);
        int ans = 0;
        // 左闭右开窗口左边界的位置
        int left = -1;
        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            left = max(left, last_index[c]);
            ans = max(ans, right - left);
            last_index[c] = right;
        } 
        return ans;

        // 滑动窗口法优化，不让左指针遍历到字符串末尾
        // 时间复杂度 O(n^2)，空间复杂度 O(∣Σ∣)，
        // ∣Σ∣ 为字符集大小（即字符串中可以出现的字符数量）
        // unordered_set<char> container;
        // int ans = 0, left = 0, right = 0, tempLen = 0;
        // while(right < s.size())
        // {
        //     char c = s[right];
        //     if(container.count(c) == 0)
        //     {
        //         container.insert(c);
        //         ++right;
        //         ++tempLen;
        //         ans = max(ans, tempLen);
        //     }
        //     else
        //     {
        //         container.erase(s[left]);
        //         ++left;
        //         --tempLen;
        //     }
        // }
        // return ans;
        
        // 滑动窗口法
        // 时间复杂度 O(n^2)，空间复杂度 O(∣Σ∣)，
        // ∣Σ∣ 为字符集大小（即字符串中可以出现的字符数量）
        // 哈希集合，记录每个字符是否出现过
        // unordered_set<char> container;
        // int n = s.size();
        // // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        // int rk = 0, ans = 0;
        // // 枚举左指针的位置
        // for(int i = 0; i < n; ++i)
        // {
        //     if(i != 0)
        //     {
        //         // 左指针向右移动一格，移除一个字符
        //         container.erase(s[i - 1]);
        //     }
            
        //     while(rk < n && container.count(s[rk]) == 0)
        //     {
        //         // 不断地移动右指针
        //         container.insert(s[rk]);
        //         ++rk;
        //     }
        //     // 第 i 到 rp 个字符是一个极长的无重复字符子串
        //     ans = max(ans, rk - i);
        // }
        // return ans;
    }
};
// @lc code=end


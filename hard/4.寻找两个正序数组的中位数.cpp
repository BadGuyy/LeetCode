/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // 二分法终极优化，从对两个数组分别二分优化到了对短的数组进行二分
        // 时间复杂度O(log(min(m,n)))，空间复杂度O(1)
        // 确保nums1的size总是小于等于nums2的size
         if(nums1.size() > nums2.size())
             return findMedianSortedArrays(nums2, nums1);

        int len1 = nums1.size(), len2 = nums2.size();
        //记录二分里较小数组的的边界
        int left = 0, right = len1;
        //记录左边部分的最大值和右边部分的最小值
        int maxLeft, minRight;
        //指定划分两个数组的i和j
        int i, j;
        while(left <= right)
        {
            i = (left + right) / 2;
            j = (len1 + len2 + 1) / 2 - i;
            //定义两个数组在划分线周围的四个元素
            int leftI = (i == 0 ? INT_MIN : nums1[i - 1]);
            int rightI = (i == len1 ? INT_MAX : nums1[i]);
            int leftJ = (j == 0 ? INT_MIN : nums2[j - 1]);
            int rightJ = (j == len2 ? INT_MAX : nums2[j]);
            //二分查找最大的i值
            if(leftI <= rightJ)
            {
                maxLeft = max(leftI, leftJ);
                minRight = min(rightI, rightJ);
                left = i + 1;
            }
            else
                right = i - 1;
        }
        return (len1 + len2)  % 2 != 0 ? maxLeft : (maxLeft + minRight) / 2.0;

        // 通过利用二分法查找第k小的元素来求解中位数
        // 时间复杂度O(log((m + n)))，空间复杂度O(1)
        // int len = nums1.size() + nums2.size();
        // if (len % 2 != 0)
        //     return getKth(nums1, nums2, (len + 1) / 2);
        // else
        //     return (getKth(nums1, nums2, len / 2) +
        //         getKth(nums1, nums2, len / 2 + 1)) / 2.0;

        // 不需要合并数组，直接在遍历过程中查找中位数
        // 时间复杂度O(m+n)，空间复杂度O(1)
        // int len1 = nums1.size(), len2 = nums2.size();
        // int len = len1 + len2;
        // int left = -1, right = -1;
        // int idx1 = 0, idx2 = 0;

        // for (int i = 0; i <= len / 2; i++)
        // {
        //     left = right;
        //     if(idx1 < len1 &&
        //         (idx2 == len2 || nums1[idx1] < nums2[idx2]))
        //         right = nums1[idx1++];
        //     else
        //         right = nums2[idx2++];
        // }
        // 对奇数长度的情况进行处理
        // if(len % 2 == 0)
        //     return (left + right) / 2.0;
        // else
        //     return right;

        // 合并两个数组，在合并的数组上查找中位数
        // 时间复杂度O(m+n)，空间复杂度O(m+n)
        // int len1 = nums1.size(), len2 = nums2.size();
        // vector<int> nums(len1 + len2);
        // int idx1 = 0, idx2 = 0, mid = nums.size() / 2;
        // for (int i = 0; i < len1 + len2; i++)
        // {
        //     if (idx1 < len1 && idx2 < len2)
        //     {
        //         if (nums1[idx1] < nums2[idx2])
        //             nums[i] = nums1[idx1++];
        //         else
        //             nums[i] = nums2[idx2++];
        //     }
        //     else if (idx1 == len1)
        //         nums[i] = nums2[idx2++];
        //     else if (idx2 == len2)
        //         nums[i] = nums1[idx1++];
        // }
        // // 从合并的数组中查找中位数
        // if (nums.size() % 2 == 0)
        //     return (nums[mid - 1] + nums[mid]) / 2.0;
        // else
        //     return nums[mid];
    }

    // 获取第k小的元素，要求参数的数组必须是从小到大的
    double getKth(const vector<int>& nums1, const vector<int> nums2, int k)
    {
        int len1 = nums1.size(), len2 = nums2.size();
        // 两个数组根据二分法去掉左边被裁剪部分后的左边界
        int left1 = 0, left2 = 0;

        while (true)
        {
            //处理边界条件
            if (left1 == len1)
                return nums2[left2 + k - 1];
            if (left2 == len2)
                return nums1[left1 + k - 1];
            if (k == 1)
                return min(nums1[left1], nums2[left2]);

            //常规处理
            // 记录两个数组每次用二分法划分后比对的元素下标
            int idx1 = min(left1 + k / 2 - 1, len1 - 1);
            int idx2 = min(left2 + k / 2 - 1, len2 - 1);
            if (nums1[idx1] <= nums2[idx2])
            {
                k -= idx1 + 1 - left1;
                left1 = idx1 + 1;
            }
            else
            {
                k -= idx2 + 1 - left2;
                left2 = idx2 + 1;
            }
        }
    }
};
// @lc code=end

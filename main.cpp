#include <iostream>
#include <vector>

using namespace std;

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
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    // 通过利用二分法查找第k小的元素来求解中位数
        int len = nums1.size() + nums2.size();
        if (len % 2 != 0)
            return getKth(nums1, nums2, (len + 1) / 2);
        else
            return (getKth(nums1, nums2, len / 2) +
                getKth(nums1, nums2, len / 2 + 1)) / 2.0;
}


int main()
{
    vector<int> nums1 = {1,2,3,4,5}, nums2 = {6,7,8,9,10,11,12,13,14,15,16,17};
    double result = findMedianSortedArrays(nums1, nums2);
    cout << result << endl;

    system("pause");
    return 0;
}
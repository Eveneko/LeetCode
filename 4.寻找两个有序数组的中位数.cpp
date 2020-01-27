/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (35.22%)
 * Likes:    1164
 * Dislikes: 0
 * Total Accepted:    61.9K
 * Total Submissions: 175.4K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 *
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 *
 * 你可以假设 nums1 和 nums2 不会同时为空。
 *
 * 示例 1:
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * 则中位数是 2.0
 *
 *
 * 示例 2:
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * 则中位数是 (2 + 3)/2 = 2.5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int k1 = (len1 + len2 + 1) / 2;
        int k2 = (len1 + len2 + 2) / 2;
        int* p1 = len1 > 0 ? &nums1[0] : nullptr;
        int* p2 = len2 > 0 ? &nums2[0] : nullptr;
        int mid1 = getkth(p1, len1, p2, len2, k1);
        int mid2 = getkth(p1, len1, p2, len2, k2);
        return (mid1 + mid2) / 2.0;
    }

    int getkth(int* nums1, int len1, int* nums2, int len2, int k) {
        if (len1 > len2) return getkth(nums2, len2, nums1, len1, k);
        if (len1 == 0) return nums2[k - 1];
        if (k == 1) return min(nums1[0], nums2[0]);

        int fi = min(len1, k / 2);
        int se = k - fi;
        if (nums1[fi - 1] > nums2[se - 1])
            return getkth(nums1, len1, nums2 + se, len2 - se, k - se);
        else
            return getkth(nums1 + fi, len1 - fi, nums2, len2, k - fi);
    }
};

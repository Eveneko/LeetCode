/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (42.56%)
 * Likes:    341
 * Dislikes: 0
 * Total Accepted:    67.9K
 * Total Submissions: 159.3K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和
 * 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 *
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 *
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int res = nums[0] + nums[1] + nums[2];
        int min_diff = abs(target - res);
        for (int i = 0; i < len - 2; i++) {
            int start = i + 1;
            int end = len - 1;
            while (end > start) {
                int sum = nums[start] + nums[end] + nums[i];
                int diff = abs(target - sum);
                if (diff == 0) return sum;
                if (diff < min_diff) {
                    min_diff = diff;
                    res = sum;
                }
                if (sum < target)
                    start++;
                else
                    end--;
            }
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (36.68%)
 * Likes:    366
 * Dislikes: 0
 * Total Accepted:    51.5K
 * Total Submissions: 140.2K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n
 * 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素
 * a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 *
 * 注意：
 *
 * 答案中不可以包含重复的四元组。
 *
 * 示例：
 *
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 *
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int size = nums.size();
        if (size < 4 || nums.front() > 0 || nums.back() < 0) return res;
        for (int k = 0; k <= size - 4; k++) {
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            for (int l = k + 1; l <= size - 3; l++) {
                if (l > k + 1 && nums[l] == nums[l - 1]) continue;
                int i = l + 1;
                int j = size - 1;
                while (i < j) {
                    if (nums[i] + nums[j] + nums[k] + nums[l] > target)
                        j--;
                    else if (nums[i] + nums[j] + nums[k] + nums[l] < target)
                        i++;
                    else {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (i < j && nums[i] == nums[i + 1]) i++;
                        while (i < j && nums[j] == nums[j - 1]) j--;
                        i++;
                        j--;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

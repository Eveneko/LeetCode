/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (73.61%)
 * Likes:    504
 * Dislikes: 0
 * Total Accepted:    70.7K
 * Total Submissions: 96K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 *
 * 示例:
 *
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vec;
        DFS(nums, vec, res, 0);
        return res;
    }

    void DFS(vector<int>& nums, vector<int>& vec, vector<vector<int>>& res,
             int pos) {
        if (nums.size() == pos) {
            res.push_back(vec);
            return;
        }
        for (int i = 0; i <= vec.size(); i++) {
            vec.insert(vec.begin() + i, nums[pos]);
            DFS(nums, vec, res, pos + 1);
            vec.erase(vec.begin() + i);
        }
        return;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 *
 * https://leetcode-cn.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Easy (56.23%)
 * Likes:    76
 * Dislikes: 0
 * Total Accepted:    9.4K
 * Total Submissions: 16.6K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * 给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j,
 * k) ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。
 *
 * 找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000,
 * 10000] 中。
 *
 * 示例:
 *
 *
 * 输入:
 * [[0,0],[1,0],[2,0]]
 *
 * 输出:
 * 2
 *
 * 解释:
 * 两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                mp[x * x + y * y]++;
            }
            for (auto n : mp) ans += n.second * (n.second - 1);
            mp.clear();
        }
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 *
 * https://leetcode-cn.com/problems/24-game/description/
 *
 * algorithms
 * Hard (40.15%)
 * Likes:    68
 * Dislikes: 0
 * Total Accepted:    2.9K
 * Total Submissions: 7K
 * Testcase Example:  '[4,1,8,7]'
 *
 * 你有 4 张写有 1 到 9
 * 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。
 *
 * 示例 1:
 *
 * 输入: [4, 1, 8, 7]
 * 输出: True
 * 解释: (8-4) * (7-1) = 24
 *
 *
 * 示例 2:
 *
 * 输入: [1, 2, 1, 2]
 * 输出: False
 *
 *
 * 注意:
 *
 *
 * 除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
 * 每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1,
 * 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1 是不允许的。
 * 你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool judgePoint24(vector<int>& nums) {
        vector<int> a = nums;
        sort(begin(a), end(a));
        do {
            unordered_set<double> a12 = cal(a[0], a[1]);
            unordered_set<double> a34 = cal(a[2], a[3]);
            for (double v1 : a12) {
                for (double v2 : a34) {
                    for (double r : cal(v1, v2)) {
                        if (is_ans(r)) return true;
                    }
                }
            }
            for (double v12 : a12) {
                for (double v123 : cal(v12, a[2])) {
                    for (double r : cal(v123, a[3]))
                        if (is_ans(r)) return true;
                }
            }
        } while (next_permutation(begin(a), end(a)));
        return false;
    }
    unordered_set<double> cal(double a, double b) {
        unordered_set<double> ans = {a * b, a + b, a - b, b - a};
        if (b) ans.insert(a / b);
        if (a) ans.insert(b / a);
        return ans;
    }
    bool is_ans(double a) { return abs(a - 24) < 1e-5; }
};
// @lc code=end

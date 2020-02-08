/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (48.88%)
 * Likes:    126
 * Dislikes: 0
 * Total Accepted:    21.4K
 * Total Submissions: 43.8K
 * Testcase Example:  '"0"\n"0"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 *
 * 注意：
 *
 *
 * num1 和num2 的长度都小于 5100.
 * num1 和num2 都只包含数字 0-9.
 * num1 和num2 都不包含任何前导零。
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string addStrings(string num1, string num2) {
        int p1 = num1.length() - 1;
        int p2 = num2.length() - 1;
        int carry = 0;
        string res = "";
        while (p1 >= 0 || p2 >= 0) {
            int n1 = p1 >= 0 ? num1[p1] - '0' : 0;
            int n2 = p2 >= 0 ? num2[p2] - '0' : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            res = (char)('0' + (sum % 10)) + res;
            p1--, p2--;
        }
        if (carry == 1) res = '1' + res;
        return res;
    }
};
// @lc code=end

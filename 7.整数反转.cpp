/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (32.52%)
 * Likes:    1096
 * Dislikes: 0
 * Total Accepted:    135K
 * Total Submissions: 415.1K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */
class Solution
{
public:
    int reverse(int x)
    {
        long ans = 0;
        bool sign = x < 0 ? false : true;
        int res;
        while (x != 0)
        {
            res = (x) % 10;
            if (!sign)
                res = (10 - res) % 10;
            ans = ans * 10 + res;
            x /= 10;
        }
        if (sign)
            if (ans > __INT32_MAX__)
                return 0;
            else
                return (int)ans;
        else
        {
            ans = -ans;
            if (ans < -__INT32_MAX__ - 1)
                return 0;
            else
                return (int)ans;
        }
    }
};

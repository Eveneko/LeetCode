/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.53%)
 * Likes:    1339
 * Dislikes: 0
 * Total Accepted:    189.2K
 * Total Submissions: 466K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 *
 * 有效字符串需满足：
 *
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 *
 *
 * 注意空字符串可被认为是有效字符串。
 *
 * 示例 1:
 *
 * 输入: "()"
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入: "()[]{}"
 * 输出: true
 *
 *
 * 示例 3:
 *
 * 输入: "(]"
 * 输出: false
 *
 *
 * 示例 4:
 *
 * 输入: "([)]"
 * 输出: false
 *
 *
 * 示例 5:
 *
 * 输入: "{[]}"
 * 输出: true
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    stack<char> st;
    bool isValid(string s) {
        int len = s.length();
        char top;
        for (int i = 0; i < len; i++) {
            if (st.empty())
                st.push(s[i]);
            else {
                top = st.top();
                if ((s[i] == ')' && top == '(') ||
                    (s[i] == ']' && top == '[') || (s[i] == '}' && top == '{'))
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        return st.empty();
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (35.83%)
 * Likes:    849
 * Dislikes: 0
 * Total Accepted:    176.1K
 * Total Submissions: 490.9K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 *
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 * 示例 1:
 *
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 *
 *
 * 示例 2:
 *
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 *
 *
 * 说明:
 *
 * 所有输入只包含小写字母 a-z 。
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool cmp(const string str1, const string str2) {
        return str1.length() <= str2.length();
    }
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        if (strs.size() == 0) return "";
        string res = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string tmp = "";
            for (int j = 0; j < strs[i].length(); j++) {
                if (res[j] == strs[i][j])
                    tmp += res[j];
                else {
                    res = tmp;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

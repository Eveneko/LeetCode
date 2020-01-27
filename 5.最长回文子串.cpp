/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.46%)
 * Likes:    957
 * Dislikes: 0
 * Total Accepted:    67.7K
 * Total Submissions: 265.8K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 *
 * 示例 1：
 *
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 *
 *
 * 示例 2：
 *
 * 输入: "cbbd"
 * 输出: "bb"
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         const int len = s.size();
//         int maxlen = 1;
//         int start = 0;

//         for (int i = 0; i < len; i++)
//         {
//             int j = i - 1;
//             int k = i + 1;
//             while (j >= 0 && k < len && s[j] == s[k])
//             {
//                 if (k - j + 1 > maxlen)
//                 {
//                     maxlen = k - j + 1;
//                     start = j;
//                 }
//                 j--;
//                 k++;
//             }
//         }

//         for (int i = 0; i < len; i++)
//         {
//             int j = i;
//             int k = i + 1;
//             while (j >= 0 && k < len && s[j] == s[k])
//             {
//                 if (k - j + 1 > maxlen)
//                 {
//                     maxlen = k - j + 1;
//                     start = j;
//                 }
//                 j--;
//                 k++;
//             }
//         }
//         return s.substr(start, maxlen);
//     }
// };
class Solution {
   public:
    string longestPalindrome(string s) {
        // 如果字符串为空
        if (s.empty()) return "";
        // 对字符串做一个处理，这样字符串的长度永远都是奇数
        string prep = "#";
        for (auto ch : s) {
            prep += ch;
            prep += "#";
        }
        const int size_p = prep.size();
        vector<int> dp(size_p, 0);
        // C是回文串的中心，R是回文串的最右端
        int C = 0, R = 0;
        for (int i = 0; i < size_p; i++) {
            // mirror是i关于C的对称点
            int mirror = C - (i - C);
            dp[i] = R <= i ? 0 : min(R - i, dp[mirror]);
            int start = i - dp[i], end = i + dp[i];
            // 中心扩展
            while (start - 1 >= 0 && end + 1 < size_p &&
                   prep[start - 1] == prep[end + 1]) {
                --start;
                ++end;
                ++dp[i];
            }
            // 更新R和C
            if (i + dp[i] > R) {
                R = i + dp[i];
                C = i;
            }
        }
        C = max_element(dp.begin(), dp.end()) - dp.begin();
        return s.substr((C - dp[C]) / 2, dp[C]);
    }
};

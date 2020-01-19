/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (29.93%)
 * Likes:    1934
 * Dislikes: 0
 * Total Accepted:    140.1K
 * Total Submissions: 467.5K
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        int cnt = 0;
        bool a[256];
        memset(a, false, sizeof(a));
        int fi = 0;
        int se = 0;
        while (se != s.length())
        {
            if (a[s[se]] == false)
            {
                a[s[se]] = true;
                cnt++;
                se++;
                ans = max(ans, cnt);
            }
            else
            {

                if (s[fi] == s[se])
                {
                    fi++;
                    se++;
                }
                else
                {
                    a[s[fi]] = false;
                    fi++;
                    cnt--;
                }
            }
        }
        return ans;
    }
};

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (52.08%)
 * Likes:    572
 * Dislikes: 0
 * Total Accepted:    75.8K
 * Total Submissions: 144.8K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 *
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 *
 *
 * 示例:
 *
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> letter{"",    "",    "abc",  "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits == "") return res;
        string str = "";
        DFS(digits, 0, str, res);
        return res;
    }

    void DFS(string digits, int pos, string& str, vector<string>& res) {
        if (pos == digits.size()) {
            res.push_back(str);
            return;
        }
        for (auto it : letter[digits[pos] - '0']) {
            str.push_back(it);
            DFS(digits, pos + 1, str, res);
            str.pop_back();
        }
    }
};
// @lc code=end

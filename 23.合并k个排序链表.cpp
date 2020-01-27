/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (48.49%)
 * Likes:    459
 * Dislikes: 0
 * Total Accepted:    68.3K
 * Total Submissions: 140.7K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 *
 * 示例:
 *
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    queue<ListNode*> qu;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto li : lists) {
            qu.push(li);
        }

        if (qu.empty()) {
            return nullptr;
        }

        while (qu.size() > 1) {
            ListNode* l1 = qu.front();
            qu.pop();
            ListNode* l2 = qu.front();
            qu.pop();
            ListNode* l3 = mergeTwoLists(l1, l2);
            qu.push(l3);
        }

        ListNode* res = qu.front();
        return res;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
// @lc code=end

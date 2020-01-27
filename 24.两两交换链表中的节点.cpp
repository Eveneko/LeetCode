/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (63.73%)
 * Likes:    387
 * Dislikes: 0
 * Total Accepted:    64.9K
 * Total Submissions: 101.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 *
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 *
 *
 *
 * 示例:
 *
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 *
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
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre_node = dummy;

        while (head && head->next) {
            ListNode *first_node = head;
            ListNode *second_node = head->next;
            pre_node->next = second_node;
            first_node->next = second_node->next;
            second_node->next = first_node;
            pre_node = first_node;
            head = first_node->next;
        }
        return dummy->next;
    }
};
// @lc code=end

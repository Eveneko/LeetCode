/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (38.75%)
 * Likes:    286
 * Dislikes: 0
 * Total Accepted:    22.1K
 * Total Submissions: 57K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空二叉树，返回其最大路径和。
 *
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 *
 * 示例 1:
 *
 * 输入: [1,2,3]
 *
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 *
 * 输出: 6
 *
 *
 * 示例 2:
 *
 * 输入: [-10,9,20,null,null,15,7]
 *
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 *
 * 输出: 42
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int DFS(TreeNode* node, int &val) {
        if (node == nullptr) return 0;
        int left = DFS(node->left, val);
        int right = DFS(node->right, val);
        int sum = max(0, left) + max(0, right) + node->val;
        int res = node->val + max(0, max(left, right));
        val = max(val, max(sum, res));
        return res;
    }

    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        DFS(root, val);
        return val;
    }
};
// @lc code=end

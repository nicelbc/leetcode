/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode.cn/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (55.70%)
 * Likes:    1638
 * Dislikes: 0
 * Total Accepted:    427.4K
 * Total Submissions: 766.2K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left  。请你反转从位置 left 到位置 right 的链表节点，返回
 * 反转后的链表 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目为 n
 * 1 
 * -500 
 * 1 
 * 
 * 
 * 
 * 
 * 进阶： 你可以使用一趟扫描完成反转吗？
 * 
 */
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};
// @lc code=start
#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;
        ListNode *first = head;
        ListNode *pre = nullptr;
        int tmpleft = left;
        while (--tmpleft)
        {
            pre = first;
            first = first->next;
        }
        //cout << "pre->val:" << pre->val << " first->val:" << first->val << endl;
        ListNode *last = first;
        ListNode *tmp;
        tmpleft = left;
        while (tmpleft++ <= right)
        {
            last = last->next;
        }
        //cout << "last->val:" << last->val  << endl;

        ListNode *p = last;
        tmpleft = left;
        while (tmpleft++ <= right)
        {
            tmp = first->next;
            first->next = p;
            p = first;
            first = tmp;
        }

        if(pre){
            pre->next = p;
            return head;
        } else{
            return p;
        }
    }
};
// @lc code=end


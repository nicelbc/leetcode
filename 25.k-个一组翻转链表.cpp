/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode.cn/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (67.64%)
 * Likes:    2157
 * Dislikes: 0
 * Total Accepted:    499.3K
 * Total Submissions: 737.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[2,1,4,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：head = [1,2,3,4,5], k = 3
 * 输出：[3,2,1,4,5]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中的节点数目为 n
 * 1 <= k <= n <= 5000
 * 0 <= Node.val <= 1000
 * 
 * 
 * 
 * 
 * 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？
 * 
 * 
 * 
 * 
 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1)
            return head;
        int len = 1;
        ListNode *ret = new ListNode();
        ListNode *p = ret;
        ListNode *pre;
        ListNode *last;
        ListNode *cur = head;
        while(cur){
            pre = cur;
            while (len < k && cur)
            {
                cur = cur->next;
                len++;
            }
            if(len < k ||(len == k && cur == nullptr)){
                p->next = pre;
                break;
            }
            else
            {
                //cur ->next 保存下一个节点
                ListNode *tmpnext =  cur->next;
                ListNode *tmppre = pre;//保存当前的开始反转的节点 作为返回结果的尾部
                last = cur;
                p->next = reverse(pre, last, k);
                p = tmppre;//更新p为上一次反转的末尾
                //print(ret->next);
                cur = tmpnext;
            }
            len = 1;//重置len的长度
        }

        return ret->next;
    }

    ListNode* reverse(ListNode* start, ListNode* end, int k){
        //cout << "start:" << start->val << " end " << end->val << endl;
        if (!start)
            return start;
        ListNode *pre = nullptr;
        while(k--){
            ListNode *tmp = start->next;
            start->next = pre;
            pre = start;
            start = tmp;
        }

        return pre;
    }
    void print(ListNode* p){
        cout << "ret value: ";
        while (p)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};
// @lc code=end


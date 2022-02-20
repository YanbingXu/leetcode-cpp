/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
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
    ListNode* rotateRight(ListNode* head, int k) {
        // 先遍历找到最后一个节点，指向第一个节点形成环，然后断开第n-k%n个点
        if (k == 0 || head == nullptr || head->next == nullptr)
        {
            return head;
        }

        // 遍历链表得到长度这样写，主要是需要找到curNode为当前链表最后一个节点
        int len = 1;
        ListNode* curNode = head;
        while (curNode->next)
        {
            curNode = curNode->next;
            len++;
        }

        //找到了最后一个节点，指向头节点
        curNode->next = head;

        ListNode* tarNode = head;
        for (int i = 1; i < len - k % len; i++)
        {
            tarNode = tarNode->next;
        }
        // 找到了需要断开的目标节点
        ListNode* newHead = tarNode->next;
        tarNode->next = nullptr;

        return newHead;
    }
};
// @lc code=end


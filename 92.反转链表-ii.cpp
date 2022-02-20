/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    // 2->3->4 返回成2<-3<-4
    void reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;

        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 方法一：找到left的前一位和right的后一位，断开链接，将left-right的链表反转
        // 再将leftBefore和rightAfter重新链接
        // 需要实现一个反转链表的子函数

        // 头节点可能需要变化，new一个新的dummyHead
        ListNode* dummyHead = new ListNode(-1, head);

        // 循环遍历到第leftBefore个节点
        ListNode* iterNode = dummyHead;
        for (int i = 0; i < left-1; i++)
        {
            iterNode = iterNode->next;
        }
        ListNode* leftBefore = iterNode;

        // 找到rightNode
        ListNode* rightNode = iterNode;
        for (int j = left; j <= right; j++)
        {
            rightNode = rightNode->next;

        }
        // 找到rightAfter
        ListNode* rightAfter = rightNode->next;

        // 截出leftnode和rightnode
        ListNode* leftNode = leftBefore->next;
        rightNode->next = nullptr;
        leftBefore->next = nullptr;
        reverseList(leftNode);

        // 将反转后的链表接回去
        leftBefore->next = rightNode;
        leftNode->next = rightAfter;

        return dummyHead->next;
    }
};
// @lc code=end


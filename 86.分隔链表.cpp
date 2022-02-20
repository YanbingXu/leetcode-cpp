/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        // 额外管理small和large两个链表，只用遍历一次原链表
        ListNode* small = new ListNode(0); //这两个指针没释放吧
        ListNode* smallHead = small;

        ListNode* large = new ListNode(0);
        ListNode* largeHead = large;

        while (head)
        {
            if (head->val < x)
            {
                small->next = head;
                small = small->next;
            }else{
                large->next = head;
                large = large->next;
            }

            head = head->next;
        }

        large->next = nullptr;
        small->next = largeHead->next;

        return smallHead->next;


    }
};
// @lc code=end


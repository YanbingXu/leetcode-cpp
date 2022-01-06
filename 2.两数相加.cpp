/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* curNode = head;
        int c = 0;
        while(l1 || l2 || c){
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            ListNode* node = new ListNode((n1 + n2 +c) % 10);
            curNode->next = node; // 链接到下一个节点
            curNode = node; // 更新当前节点
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            c = (n1 + n2 + c) / 10;
        }
        return head->next;
    }
};
// @lc code=end


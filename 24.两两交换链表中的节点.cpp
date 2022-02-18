/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        //法一：递归
        // if (head == nullptr || head->next == nullptr) // 如list为空或者list只有一个数，无法完成两两交换
        // {
        //     return head;
        // }
        // ListNode* one = head;
        // ListNode* two = one->next;
        // ListNode* three = two->next;

        // two->next = one;
        // one->next = swapPairs(three);

        // return two; //标好1，2，3更清楚

        // // ListNode* newHead = head->next;
        // // head->next = swapPairs(newHead->next);
        // // newHead->next = head;

        // // return newHead;

        // 法二：迭代temp->node1->node2 换成temp->node2->node1
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* temp = dummyHead;
        while (temp->next!= nullptr && temp->next->next != nullptr)
        {
            ListNode* node1 = temp->next;
            ListNode* node2 = node1->next;

            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;

            temp = node1; // 交换完成后迭代temp
        }
        ListNode* ans = dummyHead->next;
        delete dummyHead;

        return ans;
    }
};
// @lc code=end


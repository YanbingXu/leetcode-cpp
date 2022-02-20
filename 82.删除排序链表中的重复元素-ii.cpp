/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        // 是已排好序的链表，所以相同的元素都排在一块
        // head有可能需要被删掉，所以增加dummyHead
        if (head == nullptr)
        {
            return head;
        }

        ListNode* dummyHead = new ListNode(0, head);
        ListNode* curHead = dummyHead;
        while (curHead->next && curHead->next->next)
        {
            if (curHead->next->val == curHead->next->next->val)
            {
                int record = curHead->next->val;
                while (curHead->next && curHead->next->val == record)
                {
                    curHead->next = curHead->next->next;
                }

            }else {
                curHead = curHead->next;
            }

        }
        ListNode* res = dummyHead->next;
        delete dummyHead;

        return res;
    }
};
// @lc code=end


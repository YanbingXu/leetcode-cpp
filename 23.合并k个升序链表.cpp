/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // ListNode* res = new ListNode(-1);
        // ListNode* curr = res;
        // while (l1 != nullptr && l2 != nullptr)
        // {
        //     if(l1->val < l2->val) {
        //         curr->next = l1;
        //         l1 = l1->next;
        //     }else {
        //         curr->next = l2;
        //         l2 = l2->next;
        //     }
        //     curr = curr->next;
        // }

        // if (l1!= nullptr)
        // {
        //     curr->next = l1;
        // }
        // if (l2 != nullptr)
        // {
        //     curr->next = l2;
        // }

        // return res->next;

        // 递归
        if (l1 == nullptr)
        {
            return l2;
        }

        if (l2 == nullptr)
        {
            return l1;
        }

        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }


    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 方法一：顺序合并。根据刚刚做完的21题（合并两个升序链表），在外层套循环，即第i次将第i个链表和res合并
        if (lists.empty()) // 注意边界条件判定
        {
            return nullptr;
        }

        ListNode* resNode = lists[0];
        for (int i = 1; i < lists.size(); i++)
        {
            resNode = mergeTwoLists(resNode, lists[i]);
        }

        return resNode;
    }
};
// @lc code=end


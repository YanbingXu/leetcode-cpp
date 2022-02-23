/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        // 方法一：用一个线性表存储链表的节点索引
        vector<ListNode* >vec;
        ListNode* iterNode = head;
        while (iterNode)
        {
            vec.push_back(iterNode);
            iterNode = iterNode->next;
        }

        int i = 0; int j = vec.size() - 1;
        while (i<j)
        {
            vec[i]->next = vec[j];
            i++;

            vec[j]->next = vec[i];
            j--;
            if (i == j)
            {
                break;
            }

        }
        vec[i]->next = nullptr;

    }
};
// @lc code=end


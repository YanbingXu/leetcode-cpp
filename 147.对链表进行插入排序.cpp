/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        // 从后往前插
        ListNode* dummyHead = new ListNode(-101, head); //常规操作，new一个dummyHead，防止head变化
        ListNode* lastNode = dummyHead->next; // 维护一个lastnode表示被排好序的最后一个节点
        ListNode* curNode = lastNode->next; // 维护一个curNode表示当前做插入的节点

        while (curNode)
        {
           if (curNode->val < lastNode->val)
           {
               // 遍历已排序链表找到当前需要插入的位置
               ListNode* iterNode = dummyHead; // iter一定是 dummyhead为了防止4，1，2，3这种情况，此时iter = dummyHead
               while (iterNode->next->val <= curNode->val)
               {
                   iterNode = iterNode->next;
               }
               // 完成插入-1,3,5,2,7:last = 5,cur = 2, iter = -1;
               lastNode->next = curNode->next;
               curNode->next = iterNode->next;
               iterNode->next = curNode;

           } else {
               // 不需要改变位置直接把lastNode往后移
               lastNode = lastNode->next;
           }
           curNode = lastNode->next; // 下一个curNode
        }
        return dummyHead->next;

    }
};
// @lc code=end


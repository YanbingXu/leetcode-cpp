/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
        // 已排好序的链表，那么所有的重复元素是排在一块的。
        if (head == nullptr)
        {
            return head;
        }

        ListNode* curNode = head;

        // 当我们遍历到链表的最后一个节点时，cur.next 为空节点，如果不加以判断，访问 cur.next 对应的元素会产生运行错误。
        // 因此我们只需要遍历到链表的最后一个节点，而不需要遍历完整个链表。
        while (curNode->next)
        {
            if(curNode->val == curNode->next->val){
                curNode->next = curNode->next->next;
            }else {
                curNode = curNode->next;
            }
        }
        return head;

    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    int getListLen(ListNode* head) {
        int length = 0;
        while (head)
        {
            length++;
            head = head->next;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 法一：遍历链表：链表的做法通常要增加一个dummy节点，使得头节点失去特殊性。那么L-n+1个节点正是
        // 需要被操作的节点（删除他的next并指向nextnext）
        // ListNode* dummyHead = new ListNode(0, head);
        // int len = getListLen(head);

        // // curnode指向dummyhead做遍历
        // ListNode* curNode = dummyHead;
        // for (int i = 1; i < len - n + 1; i++)
        // {
        //     curNode = curNode->next;
        // }
        // // 现在就是第l-n+1个节点，做操作
        // curNode->next = curNode->next->next;

        // ListNode* ans = dummyHead->next;
        // delete dummyHead;
        // return ans;

        // 法二：看到倒数第n个，想到栈
        ListNode* dummyHead = new ListNode(0, head);

        ListNode* curNode = dummyHead;
        stack<ListNode*> sk;
        while (curNode)
        {
            sk.push(curNode);
            curNode = curNode->next;
        }
        // 出栈
        for (int i = 0; i < n; i++)
        {
            sk.pop();
        }
        // 此时栈顶正好是需要被删除节点的前一个节点
        ListNode* prevNode = sk.top();
        prevNode->next = prevNode->next->next;

        ListNode* ans = dummyHead->next;
        delete dummyHead;
        return ans;

    }
};
// @lc code=end


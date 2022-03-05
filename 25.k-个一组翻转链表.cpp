/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* pre = nullptr;
        while (curr != nullptr)
        {
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // 参考解题链接 https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/tu-jie-kge-yi-zu-fan-zhuan-lian-biao-by-user7208t/
        // (图片非常清晰)
        // 1.链表分区为已翻转部分+待翻转部分+未翻转部分 每次翻转前，要确定翻转链表的范围，这个必须通过 k 此循环来确定
        // 2. 初始需要两个变量 pre 和 end，pre 代表待翻转链表的前驱，end 代表待翻转链表的末尾 ，方便翻转完成后把已翻转部分和未翻转部分连接起来
        // 3. 经过k次循环，end 到达末尾，记录待翻转链表的后继 next = end.next
        // 4. 翻转链表，然后将三部分链表连接起来，然后重置 pre 和 end 指针，然后进入下一次循环
        // 5. 特殊情况，当翻转部分长度不足 k 时，在定位 end 完成后，end==null，已经到达末尾，说明题目已完成，直接返回即可
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* pre = dummyHead;
        ListNode* end = dummyHead;
        while (end != nullptr)
        {
            for(int i = 0; i<k && end!= nullptr; i++) {
                end = end->next;
            }
            // 当end == nullptr，直接返回（代表情况5，i<5满足， end!=nullptr不满足）
            if (end == nullptr)
            {
                break;
            }

            ListNode* start = pre->next;
            ListNode* next = end->next;
            // 断开 end->next,开始反转，反转函数参考206题（反转链表）
            end->next = nullptr;
            pre->next = reverseList(start);
            start->next = next;

            // 重置pre 和 end指针， 进入下一次循环；
            pre = start;
            end = pre; // end需要更新因为经过翻转end已经不在原位
        }
        return dummyHead->next;

    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // // 法一：递归 递归方程是 list1[0] <list2[0] => list1[0] + merge(list1(1:), list2)
        // // 否则，list2[0] + merge(list1, list2(1:))。 递归停止条件是出现空链表。记得补充考虑边界条件
        // if (list1 == nullptr) {
        //     return list2;
        // }

        // if (list2 == nullptr)
        // {
        //     return list1;
        // }

        // if (list1->val <= list2->val)
        // {
        //     // 断开list1->next
        //     list1->next = mergeTwoLists(list1->next, list2);
        //     return list1;
        // }else {
        //     list2->next = mergeTwoLists(list1, list2->next);
        //     return list2;
        // }

        //法二：迭代
        ListNode* resNode = new ListNode(-1);
        // cout<<"test 1"<<endl;
        ListNode* curr = resNode;
        //  cout<<"test 2"<<endl;
         // 当l1和l2都不为0的时候这样处理
        while (list1 != nullptr && list2 != nullptr)
        {
            //  cout<<"test 3"<<endl;
            if(list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
                curr = curr->next;
                //  cout<<"test 4"<<endl;
            }else {
                curr->next = list2;
                list2 = list2->next;
                curr = curr->next;
                //  cout<<"test 5"<<endl;
            }
            // curr = curr->next;
        }
        // 如果l1或者l2还不为空，接在curr后面
        if (list1 != nullptr)
        {
            curr->next = list1;
        }else {
            curr->next = list2;
        }

        return resNode->next;



    }
};
// @lc code=end


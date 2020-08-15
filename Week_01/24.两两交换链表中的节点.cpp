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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp = new ListNode(-1);
        temp->next = head;
        ListNode *prev = temp;
        while (head && head->next) {
            ListNode *first = head;
            ListNode *second = head->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            head = first->next;
            prev = first;
        }
        return temp->next;
    }
};
// @lc code=end


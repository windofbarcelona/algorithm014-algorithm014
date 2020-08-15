/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
        /*ListNode *p = head;
        while (p) {
            mystack.push(p);
            p = p->next;
        }
        ListNode *myhead = mystack.top();
        mystack.pop();
        ListNode *tail = myhead;
        while (!mystack.empty()) {
            tail->next = mystack.top();
            mystack.pop();
            tail = tail->next;
        }
        tail->next = nullptr;
        return myhead;*/
    }
    stack<ListNode*> mystack;
};
// @lc code=end


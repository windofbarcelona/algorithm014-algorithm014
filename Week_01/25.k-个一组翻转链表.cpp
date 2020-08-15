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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    pair<ListNode*, ListNode*> myReverse(ListNode *head, ListNode *tail) {
        /* 
        下面注释是官方题解的交换方法，没注释的是根据 206 题做得交换方法
        与206的区别在于，206把一整条链表进行反转，这里只是一截，所有循环的终止条件要改变
        */
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *nex = tail->next;
        while (cur != nex) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
       /*ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }*/
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next= head;
        ListNode* pre = hair;
        while (head) {
            ListNode *tail = pre;
            for (int i=0;i<k;i++) {
                tail = tail->next;
                if (!tail) 
                    return hair->next;
            }
            ListNode* nex = tail->next;
            pair<ListNode*, ListNode*> res = myReverse(head, tail);
            head = res.first;
            tail = res.second;
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = pre->next;
        }
        return hair->next;
    }
};
// @lc code=end


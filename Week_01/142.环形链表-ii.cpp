// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem142.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        /*if (!head || !head->next)
            return nullptr;
        set<ListNode*>mySet;
        ListNode *p = head;
        while (p) {
            if (mySet.find(p) != mySet.end()) {
                return p;
            }
            mySet.insert(p);
            p = p->next;
        }
        return nullptr;*/
        if (!head || !head->next)
            return nullptr;
        ListNode *fast = head, *slow = head;
        while (true) {
            if (!fast || !fast->next)
                return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                break;
        }
        fast = head;
        while (true) {
            if (fast == slow)
                break;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
// @lc code=end


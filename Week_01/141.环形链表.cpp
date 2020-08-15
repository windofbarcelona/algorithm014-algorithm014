// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem141.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        //解法一 是哈希表，注释中是快慢指针
        if(!head || !head->next)
            return false;
        /*set<ListNode *>myset;
        ListNode *p1=head;
        while (p1){
            if (myset.find(p1)!=myset.end())
                return true;
            myset.insert(p1);
            p1=p1->next;
            
        }
        return false;*/  
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while (p1!=p2) {
            if(!p2 || !p2->next)
                return false;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return true;
    }
};
// @lc code=end


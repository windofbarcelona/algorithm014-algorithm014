/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
class MyCircularDeque {
public:
    int size = 0, maxsize = 0;
    struct ListNode {
        int data;
        ListNode *next;
        ListNode *pre;
        ListNode() :data(-1),next(nullptr),pre(nullptr){}
        ListNode(int val):data(val),next(nullptr),pre(nullptr){}
    };
    ListNode *head,*tail;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        maxsize = k;
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        head->pre = tail;
        tail->next = head;
        tail->pre = head;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull())
            return false;
        ListNode *node = new ListNode(value);
        node->next = head->next;
        node->pre = head;
        head->next->pre = node;
        head->next = node;
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull())
            return false;
        ListNode *node = new ListNode(value);
        node->pre = tail->pre;
        node->next = tail;
        tail->pre->next = node;
        tail->pre = node;
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty())
            return false;
        ListNode *p = head->next;
        ListNode *p2 = head->next->next;
        head->next = p2;
        p2->pre = head;
        delete(p);
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty())
            return false;
        ListNode *p = tail->pre;
        ListNode *p2 = tail->pre->pre;
        p2->next = tail;
        tail->pre = p2;
        size--;
        delete(p);
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty())
            return -1;
        return head->next->data;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty())
            return -1;
        return tail->pre->data;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size==0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size==maxsize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end


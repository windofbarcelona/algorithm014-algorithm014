/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
struct LRUNode {
    int key, value;
    LRUNode* next, *pre;
    LRUNode():key(0), value(0), next(nullptr), pre(nullptr){}
    LRUNode(int k, int v):key(k), value(v), next(nullptr), pre(nullptr){}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        maxsize = capacity;
        size = 0;
        head = new LRUNode();
        tail = new LRUNode();
        head->next = tail;
        head->pre = tail;
        tail->next = head;
        tail->pre = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) 
            return -1;
        auto node = cache[key];
        move2head(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            //not found
            LRUNode* node = new LRUNode(key, value);
            cache[key] = node;
            add2head(node);
            size++;
            if (size > maxsize) {
                auto node = deleteTail();
                cache.erase(node->key);
                delete node;
                size--;
            }
        }
        else {
            //find
            auto node = cache[key];
            node->value = value;
            move2head(node);
        }
    }
    void add2head(LRUNode* node) {
        LRUNode* temp = head->next; 
        node->next = temp;
        node->pre = head;
        temp->pre = node;
        head->next = node;
    }
    void move2head(LRUNode* node) {
        deleteNode(node);
        add2head(node);
    }
    void deleteNode(LRUNode* node) {
        node->next->pre = node->pre;
        node->pre->next = node->next;
    }
    LRUNode* deleteTail() {
        auto node = tail->pre;
        deleteNode(node);
        return node;
    }
private:
    int size, maxsize;
    unordered_map<int, LRUNode*> cache;
    LRUNode* head, *tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


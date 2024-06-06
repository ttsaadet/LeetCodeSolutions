#include "common.h"
struct node{
    struct node* prev = 0;
    struct node* next = 0;
    int val;
    int key;
};

class LRUCache {
    
private:
    unordered_map<int,node*> cache;
    int mCap; 
    node *tail;
    node *head;
    int count = 0;
public:
    LRUCache(int capacity) {
        mCap = capacity; 
        head = nullptr;
        tail = nullptr;
    }
    void createBond(node* old, node* newBond){
        if(!old) return;
        if(old->prev)
            old->prev->next = old->next;
        if(old->next){
            old->next->prev = old->prev;
        }
        newBond->prev = old;
        old->next = newBond;

    }
    int get(int key) {
        auto it = cache.find(key);
        if(it != cache.end()){
            node * n = it->second;
            if(n == tail && tail != head){
                tail = tail->prev;
            }
            if(n != head){
                createBond(n, head);
            }
            head = n;
            return n->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if(it == cache.end()){ // if its new key
            node *n = new node();
            n->val = value;
            n->next = head;
            n->key = key;
            if(head){
                head->prev = n;
            }
            else{
                tail = n;
            }
            head = n;
            cache[key] = n;
            count++;
        }
        else{
            node * n = it->second;
            n->val = value;
            if(n == tail && tail != head){
                tail = tail->prev;
            }
            if(n != head){
                createBond(n, head);
                head = n;
            }
        }
        if(count > mCap){
            node* tmp = tail->prev;
            cache.erase(tail->key);
            delete tail;
            tail = tmp;
            tail->next = nullptr;
            count--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 int main(){
    LRUCache lru(1);

    lru.put(2,1);
     lru.put(2,2);
    lru.get(2);
    lru.put(1,1);
    lru.put(4,1);
    lru.get(2);
    
     
      return 1;
 }
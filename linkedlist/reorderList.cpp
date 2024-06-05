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
#include "common.h"
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        stack<ListNode*> reverse;
        vector<ListNode*> forward;
        bool isForward = true;
        ListNode* it = head;
        int cnt = 0;
        while(it!=nullptr){
            cnt++;
            it = it->next;
        }
        int i= 0;
        while(head != nullptr){
            if(i < cnt /2){
                forward.push_back(head);
            }
            else{
                reverse.push(head);
            }
            i++;
            head = head->next;
        }
        isForward = true;
        i = 0;
        ListNode* root = nullptr, *tmp = nullptr;
        while(i < forward.size() || !reverse.empty()){
            if(isForward && i < forward.size()){
                if(!root){
                    root = forward[i];
                    tmp = root;
                }
                else{
                    tmp->next = forward[i];
                    tmp = tmp->next;
                }
                isForward = false;
                i++;
            }
            else if(isForward == false && !reverse.empty()){
                if(!root){
                    root = reverse.top();
                    tmp = root;
                }
                else{
                    tmp->next = reverse.top();
                    tmp = tmp->next;
                }
                isForward = true;
                reverse.pop();
            }
            if(reverse.empty()) isForward = true;
            if(i >= forward.size()) isForward = false;
        }
        tmp->next = nullptr;
        head = root;
    }
};


int main(){
    vector<int>vec{1,2,3,4};
    ListNode* head = create(vec);
    Solution s;
    s.reorderList(head);
    print(head);
}
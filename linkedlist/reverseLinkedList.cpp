/*https://leetcode.com/problems/reverse-linked-list/*/
#include "common.h"


class Solution {
public:
    ListNode* create(vector<int> vec ){
        ListNode* head = new ListNode(vec[0]);
        ListNode* tmp = head;
        for(int i = 1; i < vec.size(); i++){
            ListNode* l = new ListNode(vec[i]);
            tmp->next = l;
            tmp = tmp->next;
        }
        return head;
    }
    void print(ListNode* head){
        while(head != nullptr){
            cout << head->val << " " << endl;
            head = head->next;
        }
        
    }
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> stack;
        if(head == nullptr) return nullptr;
        while(head != nullptr){
            stack.push(head);
            head = head->next;
        }
        ListNode * root;
        if(!stack.empty())
        {
            root = stack.top();
            stack.pop();
        }
        ListNode * tmp = root;
        while(!stack.empty()){
            ListNode * l = stack.top();
            tmp->next = l;
            tmp = tmp->next;
            stack.pop();
        }

        tmp->next = nullptr;
        return root;
    }
};


int main(){
    vector<int> vec{1,2,3,4,5};
    Solution s;
    ListNode* l = s.create(vec);
    l = s.reverseList(l);
    s.print(l);
}
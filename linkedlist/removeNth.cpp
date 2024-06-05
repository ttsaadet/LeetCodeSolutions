#include "common.h"


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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0;
        ListNode* tmp = head;
        int count = 0;
        while(tmp){
            count++;
            tmp = tmp->next;
        }
        if(count == 0) return head;
        
        if(count == n) head = head->next;
        tmp = head;
        while(tmp!= nullptr){
            if(i == count - n - 1 && tmp->next != nullptr){
                tmp->next = tmp->next->next;
            }
            tmp = tmp->next;
            i++;
        }  
        return head;    
    }
};

int main(){
    vector<int>vec{1,2,3,4,5};
    ListNode* l = create(vec);
    Solution s;
    l = s.removeNthFromEnd(l, 5);
    print(l);
}
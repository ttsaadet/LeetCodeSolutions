/*https://leetcode.com/problems/merge-two-sorted-lists/description/*/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* root = nullptr, *itRoot;
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode*l1 = list1;
        ListNode*l2 = list2;
        

        while(l1 != nullptr || l2 != nullptr){
            ListNode*tmp;
            if(l1 != nullptr && l2 != nullptr){
                if(l1->val < l2->val){
                    tmp = l1;
                    l1 = l1->next;
                }
                else{
                    tmp = l2;
                    l2 = l2->next;
                }
            }
            else if(l1 != nullptr){
                tmp = l1;
                l1 = l1->next;
            }
            else {
                tmp = l2;
                l2 = l2->next;
            }
            
            if(root == nullptr){
                root = tmp;
                itRoot = tmp;
            }
            else{
                itRoot->next = tmp;
                itRoot = itRoot->next;
            }
            }
        return root;
    }
};


int main()
{
    Solution s;
    vector<int>vec{1,2,3,4};
    vector<int>vec2{1,2,4,8};
    
    ListNode* l1 = s.create(vec);
    ListNode* l2 = s.create(vec2);

    ListNode* head = s.mergeTwoLists(l1,l2);
    s.print(head);
    
}
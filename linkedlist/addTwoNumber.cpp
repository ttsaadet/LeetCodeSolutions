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
    void setCarry(int * carry, int *val){
        if(*val > 9){
            *val = *val % 10;
            *carry = 1;
        }
        else{
            *carry = 0;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val = 0;
        int carry = 0;
        ListNode * root = nullptr, *tmp;
        while(l1 || l2){
            if(l1 && l2){
                val = l1->val + l2->val + carry;
                setCarry(&carry, &val);
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1){
                val = l1->val + carry;
                setCarry(&carry, &val);
                l1 = l1->next;
            }
            else if(l2){
                val = l2->val + carry;
                setCarry(&carry, &val);
                l2 = l2->next;
            }

            if(!root){
                root = new ListNode(val);
                tmp = root;
            }
            else{
                tmp->next = new ListNode(val);
                tmp = tmp->next;
            }
        }
        if(carry){
            tmp->next = new ListNode(1);
            tmp = tmp->next;
        }
        return root;
    }
};

int main(){
    vector<int> vec1{1,2,3};
    vector<int> vec2{1,2,3};
    ListNode* l1 = create(vec1);
    ListNode* l2 = create(vec2);
    Solution s;
    ListNode* sum = s.addTwoNumbers(l1,l2);
    print(sum);
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stack>
#include <assert.h>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
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
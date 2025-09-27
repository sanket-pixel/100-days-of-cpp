#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int val):val(val),next(nullptr){};
};


class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    int position = 1;
    ListNode* previous = head;
    ListNode *node_left;
    while (position<left-1) {
      previous=previous->next;
      position++;
    }
    ListNode* current=previous->next;
    ListNode* node_before_left = previous;
    if (left==1) {
      node_left=previous;
    } else {
      node_left = current;
    }
    while (position<right) {
      ListNode *temp = current->next;
      current->next=previous;
      previous = current;
      current = temp;
      position++;
    }
    if (left>1) {
      node_before_left->next=previous;
    } else {
      head=previous;
    }
    node_left->next = current;
    return head;
  }
};


int main() {
  ListNode *head = new ListNode(1);
  ListNode *current = head;
  for (int i =2;i<=6;i++) {
    ListNode *new_node = new ListNode(i);
    current->next  = new_node;
    current = new_node;
  }
  Solution sol;
  head = sol.reverseBetween(head,2,5);
  current=head;
  while (current!=nullptr) {
    std::cout << current->val << " ";
    current=current->next;
  }
  std::cout<< std::endl;
}
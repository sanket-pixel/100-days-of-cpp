#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int val) : val(val), next(nullptr) {};
};

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    if (head == nullptr) {
      return head;
    }
    while (head->val == val) {
      head = head->next;
      if (head == nullptr) {
        return head;
      }
    }
    ListNode *previous = head;
    ListNode *current = previous->next;
    while (current != nullptr) {
      ListNode *next_node = current->next;
      if (current->val == val) {
        previous->next = next_node;
      } else {
        previous = current;
      }
      current = next_node;
    }
    return head;
  }
};

int main() {
  ListNode *head = new ListNode(1);
  ListNode *current = head;
  for (int i = 2; i <= 5; i++) {
    ListNode *new_node = new ListNode(1);
    current->next = new_node;
    current = new_node;
  }
  // ListNode *new_node = new ListNode(5);
  // current->next = new_node;
  current = head;
  while (current != nullptr) {
    std::cout << current->val << " ";
    current = current->next;
  }
  std::cout << std::endl;
  Solution sol;
  head = sol.removeElements(head, 1);
  current = head;
  while (current != nullptr) {
    std::cout << current->val << " ";
    current = current->next;
  }
  return 0;
}
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int val) : val(val), next(nullptr) {};
};

ListNode *reverseList(ListNode *head) {
  ListNode *prev = nullptr;
  ListNode *curr = head;
  while (curr != nullptr) {
    ListNode *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  return prev;
}

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *head1, ListNode *head2) {
    ListNode *head_combined = nullptr;
    ListNode *temp = nullptr;
    while (head1 != nullptr && head2 != nullptr) {
      if (head1->val <= head2->val) {
        temp = head1;
        head1 = head1->next;
      } else {
        temp = head2;
        head2 = head2->next;
      }
      temp->next = head_combined;
      head_combined = temp;
    }
    while (head1 != nullptr) {
      temp = head1;
      head1 = head1->next;
      temp->next = head_combined;
      head_combined = temp;
    }
    while (head2 != nullptr) {
      temp = head2;
      head2 = head2->next;
      temp->next = head_combined;
      head_combined = temp;
    }
    ListNode *final_combined_head = reverseList(head_combined);
    return final_combined_head;
  }
};

int main() {
  std::vector<int> val1{1, 2, 4, 5, 6};
  std::vector<int> val2{1, 2, 3};
  ListNode *head1 = new ListNode(val1.at(0));
  ListNode *current = head1;
  for (int i = 1; i < 5; i++) {
    ListNode *new_node = new ListNode(val1.at(i));
    current->next = new_node;
    current = new_node;
  }
  ListNode *head2 = new ListNode(val2.at(0));
  current = head2;
  for (int i = 1; i < 3; i++) {
    ListNode *new_node = new ListNode(val2.at(i));
    current->next = new_node;
    current = new_node;
  }
  current = head1;
  while (current != nullptr) {
    std::cout << current->val << " ";
    current = current->next;
  }
  std::cout << std::endl;
  current = head2;
  while (current != nullptr) {
    std::cout << current->val << " ";
    current = current->next;
  }
  std::cout << std::endl;
  Solution sol;
  ListNode *merged_list_head = sol.mergeTwoLists(nullptr, nullptr);
  current = merged_list_head;
  while (current != nullptr) {
    std::cout << current->val << " ";
    current = current->next;
  }
  std::cout << std::endl;
}
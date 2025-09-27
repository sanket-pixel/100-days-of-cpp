#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

struct ListNode {
  int value;
  ListNode *next;
  ListNode(int value, ListNode *next) : value(value), next(next) {}
  ListNode(int value) : value(value), next(nullptr) {}
};

ListNode *reverseList(ListNode *head) {
  if (head == nullptr) {
    return head;
  }
  ListNode *previous = head;
  ListNode *current = previous->next;
  int count = 0;
  while (current != nullptr) {
    ListNode *temp = current->next;
    current->next = previous;
    if (count == 0) {
      previous->next = nullptr;
      count++;
    }
    previous = current;
    current = temp;
  }
  return previous;
}

int main() {
  ListNode *head = new ListNode(1);
  ListNode *current = head;
  for (int i = 2; i <= 10; i++) {
    ListNode *new_node = new ListNode(i);
    current->next = new_node;
    current = new_node;
  }
  current = head;
  while (current != nullptr) {
    std::cout << current->value << " " << std::endl;
    current = current->next;
  }
  std::cout << std::endl;
  ListNode *new_head = reverseList(head);
  current = new_head;
  while (current != nullptr) {
    std::cout << current->value << " " << std::endl;
    current = current->next;
  }
}
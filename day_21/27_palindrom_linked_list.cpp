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
  bool isPalindrome(ListNode *head) {
    // find the middle
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *second_half_rev = reverseList(slow);
    ListNode *first_half = head;
    while (second_half_rev != nullptr) {
      if (first_half->val != second_half_rev->val) {
        return false;
      }
      first_half = first_half->next;
      second_half_rev = second_half_rev->next;
    }
    return true;
  }

  bool isPalindrome2(ListNode *head) {
    // find the middle
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *middle_node = slow;
    ListNode *previous = head;
    ListNode *current = previous->next;
    while (previous != middle_node) {
      ListNode *temp = current->next;
      current->next = previous;
      previous = current;
      current = temp;
    }
    ListNode *current_1 = previous;
    if (fast->next == nullptr) {
      current_1 = previous->next;
    }
    ListNode *current_2 = current;
    while (current_2 != nullptr) {
      if (current_1->val != current_2->val) {
        return false;
      }
      current_1 = current_1->next;
      current_2 = current_2->next;
    }
    return true;
  }
};

int main() {
  std::vector<int> values{1, 2, 2, 1};
  ListNode *head = new ListNode(values.at(0));
  ListNode *current = head;
  for (int i = 1; i < 4; i++) {
    ListNode *new_node = new ListNode(values.at(i));
    current->next = new_node;
    current = new_node;
  }
  current = head;
  while (current != nullptr) {
    std::cout << current->val << " ";
    current = current->next;
  }
  std::cout << std::endl;
  Solution sol;
  bool result = sol.isPalindrome(head);
  if (result) {
    std::cout << "The linked list is palindrome" << std::endl;
  } else {
    std::cout << "The linked list is NOT palindrome" << std::endl;
  }
}
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycleslow(ListNode *head) {
    if (head == nullptr) {
      return false;
    }
    std::unordered_set<ListNode *> visited;
    ListNode *current = head;
    while (current->next != nullptr) {
      if (visited.find(current) == visited.end()) {
        visited.insert(current);
      } else {
        return true;
      }
      current = current->next;
    }
    return false;
  }

  bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  std::vector<int> values{3, 2, 0, -4};
  ListNode *head = new ListNode(values.at(0));
  ListNode *current = head;
  for (int i = 1; i < 4; i++) {
    ListNode *new_node = new ListNode(values.at(i));
    current->next = new_node;
    current = new_node;
  }
  current->next = head->next;
  Solution sol;
  bool has_cycle = sol.hasCycle(head);
  if (has_cycle) {
    std::cout << "List has cycle" << std::endl;
  } else {
    std::cout << "List does not have cycle" << std::endl;
  }
}

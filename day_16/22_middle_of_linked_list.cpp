#include <algorithm>
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *middleNode2loops(ListNode *head) {
    ListNode *current_node = head;
    int total_nodes = 1;
    while (current_node->next != nullptr) {
      total_nodes += 1;
      current_node = current_node->next;
    }
    int middle_node_idx = total_nodes / 2;
    current_node = head;
    for (int i = 0; i < middle_node_idx; i++) {
      current_node = current_node->next;
    }
    return current_node;
  }

  ListNode *middleNode(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next!=nullptr && fast->next->next!=nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};

int main() {
  ListNode *head = new ListNode(1);
  ListNode *current = head;
  for (int i = 2; i <= 6; i++) {
    ListNode *node = new ListNode(i);
    current->next = node;
    current = node;
  }
  Solution sol;
  ListNode *middle_node = sol.middleNode(head);
}

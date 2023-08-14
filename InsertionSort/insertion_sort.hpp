#pragma once

// https://leetcode.com/problems/insertion-sort-list/

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    ListNode *cur = head;

    std::vector<int> nums;
    while (cur) {
      nums.push_back(cur->val);
      cur = cur->next;
    }

    for (int i = 1; i < nums.size(); ++i) {
      int j = i;
      while (j > 0 && nums[j] < nums[j - 1]) {
        std::swap(nums[j], nums[j - 1]);
        j--;
      }
    }

    cur = head;
    for (int i = 0; i < nums.size(); ++i) {
      cur->val = nums[i];
      cur = cur->next;
    }
    return head;

    /*
    ListNode *cur = head;
    while (cur) {
      ListNode *next = cur->next;

      ListNode *insert = head;
      while (insert->next->val < cur->val) insert = insert->next;

      cur->next = insert->next;
      insert->next = cur;

      cur = next;
    }

    return head;
    */
  }
};

#pragma once

#include <vector>

// https://leetcode.com/problems/sort-an-array/
class Solution {
public:
  std::vector<int> sortArray(std::vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
      int min_pos = i;
      for (int j = i; j < nums.size(); ++j) {
        if (nums[j] < nums[min_pos]) min_pos = j;
      }
      std::swap(nums[i], nums[min_pos]);
    }
    return nums;
  }
};

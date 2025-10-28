/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not
matter. Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.


Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/
#include <algorithm>
#include <vector>
using namespace std;
// 重點：
// nums[i] + nums[j] + nums[k] = 0?
// 不重複的組合
// 解法：雙指標（Two Pointers）
// 1. 先排序
// 2. 固定一個數 nums[i]，用雙指標找另外兩個數
// 3. 跳過重複的數字避免重複組合

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int len = nums.size();

    // 先排序
    sort(nums.begin(), nums.end());
    // 長度不足 3，直接返回空陣列
    if (len < 3) {
      return {};
    }
    vector<vector<int>> res;
    // 遍歷陣列，固定第一個數
    for (int i = 0; i < len - 2; i++) {
      // 起點大於 0，不可能湊成 0（因為已排序，後面的數更大）
      if (nums[i] > 0) {
        break;
      }

      // 跳過相同的起點，避免重複
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      // 雙指標：left 從 i+1 開始，right 從最後開始
      int left = i + 1;
      int right = len - 1;

      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];

        if (sum == 0) {
          // 找到一組解
          res.push_back({nums[i], nums[left], nums[right]});

          // 跳過重複的數字
          while (left < right && nums[left] == nums[left + 1]) {
            left++;
          }
          while (left < right && nums[right] == nums[right - 1]) {
            right--;
          }

          // 左右各移動一格，繼續尋找下一組解
          left++;
          right--;
        } else if (sum < 0) {
          // 總和太小，left 往右移動（取更大的值）
          left++;
        } else {
          // 總和太大，right 往左移動（取更小的值）
          right--;
        }
      }
    }

    return res;
  }
};
/*
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n = s.length();
            int maxLength{0};
            for (int i = 0; i < n; i++) {
                // 創建Map來儲存字符和其出現的索引
                unordered_map<char, int> charMap;
                for (int j = i; j < n; j++) {
                    // 如果字符已經出現過，則跳出循環
                    if (charMap.find(s[j]) != charMap.end()) {
                        break;
                    }
                    // 如果字符沒有出現過，則將其添加到Map中
                    charMap[s[j]] = j;
                }
                // 更新最大長度（無論是否遇到重複字符都要更新）
                maxLength = max(maxLength, static_cast<int>(charMap.size()));
            }
            return maxLength;
        }
    };
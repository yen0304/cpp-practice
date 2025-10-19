/*
Given an integer x, return true if x is a palindrome, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Constraints:

-231 <= x <= 231 - 1

*/
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            //挑戰不用轉換為字串來解題
            //簡單說如果該數字是回文數，代表該數字與其反轉後的數字相除餘數為0
            if (x < 0) {
                return false;
            }
            int original = x; // 儲存原始數字
            long long reversed = 0; // 使用 long long 避免溢位
            // 當原始數字大於0時，繼續反轉數字
            while (x > 0) {
                // 反轉數字等於反轉數字 * 10 + 原始數字 % 10
                reversed = reversed * 10 + x % 10;
                // 原始數字等於原始數字 / 10
                x /= 10;
            }
            return original == reversed;
        }
    };
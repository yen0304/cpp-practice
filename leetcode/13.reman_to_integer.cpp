/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

I can be placed before V (5) and X (10) to make 4 and 9.  // I可以是V或X的前面，表示4或9
X can be placed before L (50) and C (100) to make 40 and 90.  // X可以是L或C的前面，表示40或90
C can be placed before D (500) and M (1000) to make 400 and 900.  // C可以是D或M的前面，表示400或900
*/
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int romanToInt(string s) {
            int result {0};
            // 減法規則 : 若「小的數」在「大的數」前面，表示要 減去 小的數。
            // 先創建一個Map來儲存羅馬數字和其對應的整數
            unordered_map<char, int> roman = {
                {'I', 1}, {'V', 5}, {'X', 10},
                {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
            };

            for (int i = 0; i < s.length(); i++) {
                // 如果右邊有更大的數字，表示這一位要減
                if (roman[s[i]] < roman[s[i + 1]]) {
                    result -= roman[s[i]];
                }
                else {
                    result += roman[s[i]];
                }
            }
            return result;
        }
};
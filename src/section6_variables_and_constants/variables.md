# C++ 語言數字變數種類

## 整數類型 (Integer Types)

### 基本整數類型
| 類型 | 關鍵字 | 大小 (位元) | 範圍 | 說明 |
|------|--------|-------------|------|------|
| 字元 | `char` | 8 | -128 到 127 | 通常用來儲存字元，但本質上是整數 |
| 短整數 | `short` | 16 | -32,768 到 32,767 | 短整數 |
| 整數 | `int` | 32 | -2,147,483,648 到 2,147,483,647 | 最常用的整數類型 |
| 長整數 | `long` | 32 或 64 | 依系統而定 | 至少 32 位元 |
| 超長整數 | `long long` | 64 | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807 | C99 標準 |

### 修飾符 (Modifiers)
- **`signed`**: 有符號整數（預設）
- **`unsigned`**: 無符號整數（只能儲存正數和零）
- **`short`**: 短整數
- **`long`**: 長整數

### 範例
```cpp
char c = 'A';                    // 字元
short s = 100;                   // 短整數
int i = 1000;                    // 整數
long l = 1000000L;               // 長整數
long long ll = 1000000000LL;     // 超長整數

unsigned char uc = 200;          // 無符號字元
unsigned int ui = 4000000000U;   // 無符號整數
```

## 浮點數類型 (Floating-Point Types)

| 類型 | 關鍵字 | 大小 (位元) | 精度 | 範圍 | 說明 |
|------|--------|-------------|------|------|------|
| 單精度 | `float` | 32 | 6-7 位小數 | ±1.2×10⁻³⁸ 到 ±3.4×10³⁸ | 單精度浮點數 |
| 雙精度 | `double` | 64 | 15-16 位小數 | ±2.3×10⁻³⁰⁸ 到 ±1.7×10³⁰⁸ | 雙精度浮點數 |
| 擴展精度 | `long double` | 80 或 128 | 19-20 位小數 | 依系統而定 | 擴展精度浮點數 |

### 範例
```cpp
float f = 3.14f;                 // 單精度浮點數
double d = 3.14159265359;        // 雙精度浮點數
long double ld = 3.141592653589793238L; // 擴展精度浮點數
```

## 布林類型 (Boolean Type)

| 類型 | 關鍵字 | 大小 (位元) | 值 | 說明 |
|------|--------|-------------|-----|------|
| 布林 | `bool` | 1 | `true` 或 `false` | C++ 內建類型，需要 `#include <iostream>` 或 `#include <cstdbool>` |

### 範例
```cpp
#include <iostream>

bool flag1 = true;               // 布林值
bool flag2 = false;              // 布林值
```

## 常數 (Constants)

### 整數常數
```cpp
int decimal = 123;               // 十進位
int octal = 0173;                // 八進位 (以 0 開頭)
int hexadecimal = 0x7B;          // 十六進位 (以 0x 開頭)
int binary = 0b1111011;          // 二進位 (C++14 標準)
```

### 浮點數常數
```cpp
float f1 = 3.14f;                // 單精度
double d1 = 3.14;                // 雙精度
double d2 = 3.14e2;              // 科學記號 (314.0)
double d3 = 3.14E-2;             // 科學記號 (0.0314)
```

## 記憶體大小查詢

```cpp
#include <iostream>

int main() {
    std::cout << "char: " << sizeof(char) << " bytes" << std::endl;
    std::cout << "short: " << sizeof(short) << " bytes" << std::endl;
    std::cout << "int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "long: " << sizeof(long) << " bytes" << std::endl;
    std::cout << "long long: " << sizeof(long long) << " bytes" << std::endl;
    std::cout << "float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "long double: " << sizeof(long double) << " bytes" << std::endl;
    
    return 0;
}
```

## 最佳實踐

1. **選擇適當的類型**: 根據資料範圍選擇最適合的類型
2. **使用 `unsigned`**: 當確定值不會是負數時使用
3. **浮點數比較**: 避免直接比較浮點數，使用容差範圍
4. **初始化變數**: 總是初始化變數以避免未定義行為
5. **使用 `const`**: 對於不會改變的值使用 `const` 關鍵字

```cpp
const int MAX_SIZE = 100;        // 常數
const double PI = 3.14159;       // 常數
```

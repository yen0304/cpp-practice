# C++ Operators

## Overview
Operators are symbols that tell the compiler to perform specific mathematical, logical, or other operations. C++ provides a rich set of operators that can be classified into several categories.

## Arithmetic Operators

### Basic Arithmetic Operators
| Operator | Name | Description | Example |
|----------|------|-------------|---------|
| `+` | Addition | Adds two operands | `a + b` |
| `-` | Subtraction | Subtracts second operand from first | `a - b` |
| `*` | Multiplication | Multiplies both operands | `a * b` |
| `/` | Division | Divides first operand by second | `a / b` |
| `%` | Modulus | Returns remainder after division | `a % b` |

### Example
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 3;
    
    cout << "a + b = " << (a + b) << endl;  // 13
    cout << "a - b = " << (a - b) << endl;  // 7
    cout << "a * b = " << (a * b) << endl;  // 30
    cout << "a / b = " << (a / b) << endl;  // 3 (integer division)
    cout << "a % b = " << (a % b) << endl;  // 1
    
    return 0;
}
```

## Assignment Operators

### Basic Assignment
The `=` operator assigns the value on the right to the variable on the left.

### Compound Assignment Operators
| Operator | Equivalent to | Description |
|----------|---------------|-------------|
| `+=` | `a = a + b` | Add and assign |
| `-=` | `a = a - b` | Subtract and assign |
| `*=` | `a = a * b` | Multiply and assign |
| `/=` | `a = a / b` | Divide and assign |
| `%=` | `a = a % b` | Modulus and assign |

### Example
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    
    cout << "Initial value: " << a << endl;
    
    a += 5;  // a = a + 5
    cout << "After += 5: " << a << endl;  // 15
    
    a -= 3;  // a = a - 3
    cout << "After -= 3: " << a << endl;  // 12
    
    a *= 2;  // a = a * 2
    cout << "After *= 2: " << a << endl;  // 24
    
    a /= 4;  // a = a / 4
    cout << "After /= 4: " << a << endl;  // 6
    
    a %= 5;  // a = a % 5
    cout << "After %= 5: " << a << endl;  // 1
    
    return 0;
}
```

## Increment and Decrement Operators

### Pre-increment/Pre-decrement
- `++variable` - Increments variable, then returns the new value
- `--variable` - Decrements variable, then returns the new value

### Post-increment/Post-decrement
- `variable++` - Returns the current value, then increments variable
- `variable--` - Returns the current value, then decrements variable

### Example
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    
    cout << "Initial value: " << a << endl;
    
    // Pre-increment
    cout << "++a = " << (++a) << endl;  // 6, a is now 6
    cout << "a = " << a << endl;        // 6
    
    // Post-increment
    cout << "a++ = " << (a++) << endl;  // 6, a is now 7
    cout << "a = " << a << endl;        // 7
    
    // Pre-decrement
    cout << "--a = " << (--a) << endl;  // 6, a is now 6
    cout << "a = " << a << endl;        // 6
    
    // Post-decrement
    cout << "a-- = " << (a--) << endl;  // 6, a is now 5
    cout << "a = " << a << endl;        // 5
    
    return 0;
}
```

## Comparison Operators

### Relational Operators
| Operator | Name | Description | Example |
|----------|------|-------------|---------|
| `==` | Equal to | Checks if two operands are equal | `a == b` |
| `!=` | Not equal to | Checks if two operands are not equal | `a != b` |
| `<` | Less than | Checks if first operand is less than second | `a < b` |
| `>` | Greater than | Checks if first operand is greater than second | `a > b` |
| `<=` | Less than or equal to | Checks if first operand is less than or equal to second | `a <= b` |
| `>=` | Greater than or equal to | Checks if first operand is greater than or equal to second | `a >= b` |

### Example
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;
    
    cout << "a = " << a << ", b = " << b << endl;
    cout << "a == b: " << (a == b) << endl;  // 0 (false)
    cout << "a != b: " << (a != b) << endl;  // 1 (true)
    cout << "a < b: " << (a < b) << endl;    // 1 (true)
    cout << "a > b: " << (a > b) << endl;    // 0 (false)
    cout << "a <= b: " << (a <= b) << endl;  // 1 (true)
    cout << "a >= b: " << (a >= b) << endl;  // 0 (false)
    
    return 0;
}
```

## Logical Operators

### Logical Operators
| Operator | Name | Description | Example |
|----------|------|-------------|---------|
| `&&` | Logical AND | Returns true if both operands are true | `a && b` |
| `||` | Logical OR | Returns true if either operand is true | `a || b` |
| `!` | Logical NOT | Returns true if operand is false | `!a` |

### Example
```cpp
#include <iostream>
using namespace std;

int main() {
    bool a = true, b = false;
    
    cout << "a = " << a << ", b = " << b << endl;
    cout << "a && b: " << (a && b) << endl;  // 0 (false)
    cout << "a || b: " << (a || b) << endl;  // 1 (true)
    cout << "!a: " << (!a) << endl;          // 0 (false)
    cout << "!b: " << (!b) << endl;          // 1 (true)
    
    // Short-circuit evaluation
    int x = 5, y = 0;
    if (x > 0 && y > 0) {  // y > 0 is not evaluated because x > 0 is false
        cout << "Both are positive" << endl;
    }
    
    return 0;
}
```

## Bitwise Operators

### Bitwise Operators
| Operator | Name | Description | Example |
|----------|------|-------------|---------|
| `&` | Bitwise AND | Performs bitwise AND operation | `a & b` |
| `|` | Bitwise OR | Performs bitwise OR operation | `a | b` |
| `^` | Bitwise XOR | Performs bitwise XOR operation | `a ^ b` |
| `~` | Bitwise NOT | Performs bitwise NOT operation | `~a` |
| `<<` | Left shift | Shifts bits to the left | `a << 2` |
| `>>` | Right shift | Shifts bits to the right | `a >> 2` |

### Example
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 12;  // Binary: 1100
    int b = 10;  // Binary: 1010
    
    cout << "a = " << a << " (binary: 1100)" << endl;
    cout << "b = " << b << " (binary: 1010)" << endl;
    
    cout << "a & b = " << (a & b) << " (binary: 1000)" << endl;  // 8
    cout << "a | b = " << (a | b) << " (binary: 1110)" << endl;  // 14
    cout << "a ^ b = " << (a ^ b) << " (binary: 0110)" << endl;  // 6
    cout << "~a = " << (~a) << endl;  // -13 (depends on system)
    cout << "a << 2 = " << (a << 2) << " (binary: 110000)" << endl;  // 48
    cout << "a >> 2 = " << (a >> 2) << " (binary: 11)" << endl;     // 3
    
    return 0;
}
```

## Conditional (Ternary) Operator

### Syntax
```cpp
condition ? expression1 : expression2
```

### Description
- If condition is true, expression1 is evaluated and returned
- If condition is false, expression2 is evaluated and returned

### Example
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;
    
    // Find maximum
    int max = (a > b) ? a : b;
    cout << "Maximum of " << a << " and " << b << " is " << max << endl;
    
    // Check if number is even or odd
    int num = 15;
    string result = (num % 2 == 0) ? "even" : "odd";
    cout << num << " is " << result << endl;
    
    // Nested ternary operator
    int x = 5, y = 10, z = 15;
    int largest = (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
    cout << "Largest among " << x << ", " << y << ", " << z << " is " << largest << endl;
    
    return 0;
}
```

## Sizeof Operator

### Description
Returns the size in bytes of a variable or data type.

### Example
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    double b = 3.14;
    char c = 'A';
    
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " bytes" << endl;
    cout << "Size of variable a: " << sizeof(a) << " bytes" << endl;
    cout << "Size of variable b: " << sizeof(b) << " bytes" << endl;
    cout << "Size of variable c: " << sizeof(c) << " bytes" << endl;
    
    return 0;
}
```

## Comma Operator

### Description
Evaluates multiple expressions and returns the value of the last expression.

### Example
```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    
    // Comma operator in assignment
    a = (b = 5, c = 10, b + c);  // a = 15
    cout << "a = " << a << endl;
    
    // Comma operator in for loop
    for (int i = 0, j = 10; i < 5; i++, j--) {
        cout << "i = " << i << ", j = " << j << endl;
    }
    
    // Comma operator in function call
    int result = (a = 10, b = 20, a + b);
    cout << "Result: " << result << endl;
    
    return 0;
}
```

## Operator Precedence and Associativity

### Precedence Table (Highest to Lowest)
| Precedence | Operator | Associativity |
|------------|----------|---------------|
| 1 | `()` `[]` `->` `.` | Left to Right |
| 2 | `++` `--` `!` `~` `+` `-` `*` `&` `sizeof` | Right to Left |
| 3 | `*` `/` `%` | Left to Right |
| 4 | `+` `-` | Left to Right |
| 5 | `<<` `>>` | Left to Right |
| 6 | `<` `<=` `>` `>=` | Left to Right |
| 7 | `==` `!=` | Left to Right |
| 8 | `&` | Left to Right |
| 9 | `^` | Left to Right |
| 10 | `|` | Left to Right |
| 11 | `&&` | Left to Right |
| 12 | `||` | Left to Right |
| 13 | `?:` | Right to Left |
| 14 | `=` `+=` `-=` `*=` `/=` `%=` | Right to Left |
| 15 | `,` | Left to Right |

### Example
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 2, b = 3, c = 4;
    
    // Without parentheses (following precedence)
    int result1 = a + b * c;  // 2 + (3 * 4) = 14
    cout << "a + b * c = " << result1 << endl;
    
    // With parentheses (explicit precedence)
    int result2 = (a + b) * c;  // (2 + 3) * 4 = 20
    cout << "(a + b) * c = " << result2 << endl;
    
    // Complex expression
    int result3 = a + b * c - a / b;  // 2 + (3 * 4) - (2 / 3) = 14 - 0 = 14
    cout << "a + b * c - a / b = " << result3 << endl;
    
    return 0;
}
```

## Type Casting Operators

### Implicit Type Conversion
Automatic conversion between compatible types.

### Explicit Type Conversion (C-style)
```cpp
(type) expression
```

### C++ Style Casting
- `static_cast` - For safe, well-defined conversions
- `dynamic_cast` - For polymorphic type conversions
- `const_cast` - For removing const qualifier
- `reinterpret_cast` - For low-level conversions

### Example
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    double b = 3.14;
    
    // Implicit conversion
    double result1 = a + b;  // int converted to double
    cout << "Implicit: " << result1 << endl;
    
    // C-style casting
    int result2 = (int)b;  // double converted to int
    cout << "C-style cast: " << result2 << endl;
    
    // C++ style casting
    int result3 = static_cast<int>(b);
    cout << "static_cast: " << result3 << endl;
    
    // Pointer casting
    int* ptr = &a;
    void* voidPtr = static_cast<void*>(ptr);
    int* intPtr = static_cast<int*>(voidPtr);
    cout << "Pointer value: " << *intPtr << endl;
    
    return 0;
}
```

## Best Practices

### 1. Use Parentheses for Clarity
```cpp
// Unclear precedence
int result = a + b * c - d / e;

// Clear precedence
int result = a + (b * c) - (d / e);
```

### 2. Avoid Side Effects in Expressions
```cpp
// Avoid
int result = (++a) + (++a);  // Undefined behavior

// Better
++a;
int result = a + a;
```

### 3. Use Appropriate Operators
```cpp
// Use compound assignment when possible
a += 5;  // Better than a = a + 5;

// Use prefix increment when return value is not needed
++i;  // Better than i++; when return value is not used
```

### 4. Be Careful with Floating-Point Comparisons
```cpp
// Avoid direct comparison
if (a == b) { ... }

// Use tolerance
if (abs(a - b) < 0.0001) { ... }
```

### 5. Use sizeof with Parentheses for Types
```cpp
// Good
sizeof(int)
sizeof(variable)

// Avoid
sizeof int  // Compilation error
```

## Common Pitfalls

### 1. Assignment vs Comparison
```cpp
int a = 5;
if (a = 10) {  // Assignment, not comparison!
    cout << "This will always execute" << endl;
}

if (a == 10) {  // Correct comparison
    cout << "This checks if a equals 10" << endl;
}
```

### 2. Integer Division
```cpp
int a = 10, b = 3;
double result = a / b;  // Result is 3, not 3.333...

// Correct way
double result = static_cast<double>(a) / b;  // Result is 3.333...
```

### 3. Operator Precedence
```cpp
int a = 2, b = 3, c = 4;
int result = a + b * c;  // 14, not 20

// Use parentheses for clarity
int result = (a + b) * c;  // 20
```

This comprehensive guide covers all the major operators in C++ with practical examples and best practices to help you write better, more efficient code.

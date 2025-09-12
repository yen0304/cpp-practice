# C++ Character and String

## Overview
C++ provides two main ways to handle text data: `char` for single characters and `string` for sequences of characters. Understanding both is essential for effective text processing in C++.

## Character (char)

### Basic Concepts
- `char` is a data type that stores a single character
- Size is typically 1 byte (8 bits)
- Can store ASCII values (0-127) or extended ASCII (0-255)
- Can be used for both characters and small integers

### Declaration and Initialization

```cpp
#include <iostream>
using namespace std;

int main() {
    // Different ways to initialize char
    char c1 = 'A';           // Character literal
    char c2 = 65;            // ASCII value
    char c3 = '\n';          // Escape sequence
    char c4 = '\0';          // Null character
    
    cout << "c1 = " << c1 << endl;  // A
    cout << "c2 = " << c2 << endl;  // A (ASCII 65)
    cout << "c3 = " << c3;          // New line
    cout << "c4 = " << c4 << endl;  // (invisible null character)
    
    return 0;
}
```

### Escape Sequences
Special characters that cannot be typed directly:

| Escape Sequence | Description | ASCII Value |
|-----------------|-------------|-------------|
| `\n` | New line | 10 |
| `\t` | Horizontal tab | 9 |
| `\r` | Carriage return | 13 |
| `\b` | Backspace | 8 |
| `\f` | Form feed | 12 |
| `\v` | Vertical tab | 11 |
| `\\` | Backslash | 92 |
| `\'` | Single quote | 39 |
| `\"` | Double quote | 34 |
| `\0` | Null character | 0 |

### Example
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello\tWorld\n";        // Hello    World
    cout << "Line 1\rLine 2\n";      // Line 2
    cout << "Back\bspace\n";         // Backspace
    cout << "Quote: \"Hello\"\n";    // Quote: "Hello"
    cout << "Path: C:\\Users\n";     // Path: C:\Users
    
    return 0;
}
```

### Character Input/Output

```cpp
#include <iostream>
using namespace std;

int main() {
    char ch;
    
    // Input a single character
    cout << "Enter a character: ";
    cin >> ch;
    cout << "You entered: " << ch << endl;
    
    // Input with get() - includes whitespace
    cout << "Enter a character (including space): ";
    ch = cin.get();
    cout << "You entered: " << ch << endl;
    
    // Input with getchar() - C-style
    cout << "Enter another character: ";
    ch = getchar();
    cout << "You entered: " << ch << endl;
    
    return 0;
}
```

### Character Functions (cctype)

```cpp
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char ch = 'A';
    
    // Character classification
    cout << "isalpha('A'): " << isalpha(ch) << endl;    // 1 (true)
    cout << "isdigit('A'): " << isdigit(ch) << endl;    // 0 (false)
    cout << "isalnum('A'): " << isalnum(ch) << endl;    // 1 (true)
    cout << "isspace(' '): " << isspace(' ') << endl;   // 1 (true)
    cout << "ispunct('!'): " << ispunct('!') << endl;   // 1 (true)
    cout << "isprint('A'): " << isprint(ch) << endl;    // 1 (true)
    cout << "iscntrl('\\n'): " << iscntrl('\n') << endl; // 1 (true)
    
    // Character conversion
    cout << "tolower('A'): " << (char)tolower(ch) << endl; // a
    cout << "toupper('a'): " << (char)toupper('a') << endl; // A
    
    return 0;
}
```

## C-Style Strings (Character Arrays)

### Basic Concepts
- Array of characters terminated by null character `\0`
- Fixed size, cannot be resized
- More memory efficient but less safe than `std::string`

### Declaration and Initialization

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    // Different ways to initialize C-style strings
    char str1[20] = "Hello";           // Size 20, content "Hello"
    char str2[] = "World";             // Size 6 (5 + null terminator)
    char str3[10] = {'H', 'i', '\0'};  // Manual initialization
    char str4[5] = "Test";             // Size 5, content "Test"
    
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    cout << "str4: " << str4 << endl;
    
    return 0;
}
```

### String Functions (cstring)

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[50] = "Hello";
    char str2[50] = "World";
    char str3[50];
    
    // String length
    cout << "Length of str1: " << strlen(str1) << endl;  // 5
    
    // String copy
    strcpy(str3, str1);
    cout << "str3 after copy: " << str3 << endl;  // Hello
    
    // String concatenation
    strcat(str1, " ");
    strcat(str1, str2);
    cout << "str1 after concatenation: " << str1 << endl;  // Hello World
    
    // String comparison
    int result = strcmp("Hello", "World");
    cout << "strcmp result: " << result << endl;  // Negative (Hello < World)
    
    // String copy with length limit
    char str4[10];
    strncpy(str4, "Hello World", 5);
    str4[5] = '\0';  // Null terminate manually
    cout << "str4: " << str4 << endl;  // Hello
    
    return 0;
}
```

### Input/Output with C-Style Strings

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char name[50];
    
    // Input with cin (stops at whitespace)
    cout << "Enter your first name: ";
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    
    // Input with cin.getline() (includes spaces)
    cout << "Enter your full name: ";
    cin.ignore();  // Clear input buffer
    cin.getline(name, 50);
    cout << "Hello, " << name << "!" << endl;
    
    // Input with cin.get() - alternative
    char sentence[100];
    cout << "Enter a sentence: ";
    cin.get(sentence, 100);
    cout << "You entered: " << sentence << endl;
    
    return 0;
}
```

## C++ String Class (std::string)

### Basic Concepts
- Dynamic string class from STL
- Automatically manages memory
- Much safer and easier to use than C-style strings
- Can be resized dynamically

### Declaration and Initialization

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Different ways to initialize string
    string str1 = "Hello";                    // Direct assignment
    string str2("World");                     // Constructor
    string str3{'H', 'e', 'l', 'l', 'o'};    // Initializer list
    string str4(5, 'A');                      // 5 copies of 'A'
    string str5(str1);                        // Copy constructor
    string str6 = str1 + " " + str2;          // Concatenation
    
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    cout << "str4: " << str4 << endl;
    cout << "str5: " << str5 << endl;
    cout << "str6: " << str6 << endl;
    
    return 0;
}
```

### String Operations

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Hello World";
    
    // Length and capacity
    cout << "Length: " << str.length() << endl;      // 11
    cout << "Size: " << str.size() << endl;          // 11
    cout << "Capacity: " << str.capacity() << endl;  // 15 (implementation dependent)
    cout << "Empty: " << str.empty() << endl;        // 0 (false)
    
    // Accessing characters
    cout << "First character: " << str[0] << endl;           // H
    cout << "Last character: " << str[str.length()-1] << endl; // d
    cout << "Character at index 6: " << str.at(6) << endl;   // W
    
    // Modifying characters
    str[0] = 'h';  // Change first character
    cout << "After modification: " << str << endl;  // hello World
    
    // Substring
    string sub = str.substr(6, 5);  // From index 6, length 5
    cout << "Substring: " << sub << endl;  // World
    
    return 0;
}
```

### String Concatenation

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "Hello";
    string str2 = "World";
    
    // Using + operator
    string result1 = str1 + " " + str2;
    cout << "Using +: " << result1 << endl;  // Hello World
    
    // Using += operator
    string result2 = str1;
    result2 += " ";
    result2 += str2;
    cout << "Using +=: " << result2 << endl;  // Hello World
    
    // Using append()
    string result3 = str1;
    result3.append(" ");
    result3.append(str2);
    cout << "Using append(): " << result3 << endl;  // Hello World
    
    // Concatenating with numbers
    int num = 42;
    string result4 = "Number: " + to_string(num);
    cout << "With number: " << result4 << endl;  // Number: 42
    
    return 0;
}
```

### String Comparison

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "apple";
    string str2 = "banana";
    string str3 = "apple";
    
    // Using == operator
    cout << "str1 == str2: " << (str1 == str2) << endl;  // 0 (false)
    cout << "str1 == str3: " << (str1 == str3) << endl;  // 1 (true)
    
    // Using compare() method
    int result1 = str1.compare(str2);
    int result2 = str1.compare(str3);
    cout << "str1.compare(str2): " << result1 << endl;  // Negative
    cout << "str1.compare(str3): " << result2 << endl;  // 0
    
    // Case-insensitive comparison (custom function)
    string str4 = "Apple";
    cout << "Case sensitive: " << (str1 == str4) << endl;  // 0 (false)
    
    return 0;
}
```

### String Search and Replace

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Hello World Hello";
    
    // Finding substrings
    size_t pos = str.find("World");
    if (pos != string::npos) {
        cout << "Found 'World' at position: " << pos << endl;  // 6
    }
    
    // Finding last occurrence
    size_t lastPos = str.rfind("Hello");
    cout << "Last 'Hello' at position: " << lastPos << endl;  // 12
    
    // Finding any character from a set
    size_t vowelPos = str.find_first_of("aeiouAEIOU");
    cout << "First vowel at position: " << vowelPos << endl;  // 1
    
    // Replacing substrings
    string newStr = str;
    newStr.replace(0, 5, "Hi");  // Replace 5 chars from position 0 with "Hi"
    cout << "After replace: " << newStr << endl;  // Hi World Hello
    
    // Erasing characters
    string eraseStr = str;
    eraseStr.erase(5, 6);  // Erase 6 chars from position 5
    cout << "After erase: " << eraseStr << endl;  // Hello Hello
    
    return 0;
}
```

### String Input/Output

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name, fullName, sentence;
    
    // Input with cin (stops at whitespace)
    cout << "Enter your first name: ";
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    
    // Input with getline() (includes spaces)
    cout << "Enter your full name: ";
    cin.ignore();  // Clear input buffer
    getline(cin, fullName);
    cout << "Hello, " << fullName << "!" << endl;
    
    // Input with getline() and delimiter
    cout << "Enter a sentence (end with #): ";
    getline(cin, sentence, '#');
    cout << "You entered: " << sentence << endl;
    
    return 0;
}
```

### String Iteration

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Hello";
    
    // Using index-based loop
    cout << "Index-based loop: ";
    for (size_t i = 0; i < str.length(); i++) {
        cout << str[i] << " ";
    }
    cout << endl;
    
    // Using range-based for loop (C++11)
    cout << "Range-based loop: ";
    for (char c : str) {
        cout << c << " ";
    }
    cout << endl;
    
    // Using iterators
    cout << "Iterator-based loop: ";
    for (auto it = str.begin(); it != str.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Using const iterators (read-only)
    cout << "Const iterator loop: ";
    for (auto it = str.cbegin(); it != str.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}
```

### String Conversion

```cpp
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    // String to number
    string numStr = "123";
    int num = stoi(numStr);  // String to int
    cout << "String to int: " << num << endl;
    
    string floatStr = "3.14";
    float f = stof(floatStr);  // String to float
    cout << "String to float: " << f << endl;
    
    // Number to string
    int value = 456;
    string str = to_string(value);
    cout << "Int to string: " << str << endl;
    
    // Using stringstream
    stringstream ss;
    ss << "Number: " << 789 << " and " << 3.14;
    string result = ss.str();
    cout << "Stringstream result: " << result << endl;
    
    // Parsing with stringstream
    string data = "John 25 85.5";
    stringstream parser(data);
    string name;
    int age;
    double weight;
    parser >> name >> age >> weight;
    cout << "Name: " << name << ", Age: " << age << ", Weight: " << weight << endl;
    
    return 0;
}
```

## String vs C-String Comparison

| Feature | std::string | C-String (char[]) |
|---------|-------------|-------------------|
| Memory Management | Automatic | Manual |
| Size | Dynamic | Fixed |
| Safety | Bounds checking | No bounds checking |
| Assignment | `=` operator | `strcpy()` |
| Concatenation | `+` operator | `strcat()` |
| Comparison | `==` operator | `strcmp()` |
| Length | `.length()` | `strlen()` |
| Performance | Slightly slower | Faster |
| Memory Usage | Higher overhead | Lower overhead |

## Best Practices

### 1. Choose the Right Type
```cpp
// Use std::string for most cases
string name = "John Doe";

// Use char only for single characters
char grade = 'A';

// Use C-strings only when interfacing with C libraries
char buffer[256];
```

### 2. Safe String Operations
```cpp
// Always check bounds with at()
string str = "Hello";
if (str.length() > 0) {
    cout << str.at(0) << endl;  // Safe
}

// Use find() safely
size_t pos = str.find("World");
if (pos != string::npos) {
    cout << "Found at: " << pos << endl;
}
```

### 3. Efficient String Concatenation
```cpp
// For multiple concatenations, use stringstream
stringstream ss;
ss << "Hello" << " " << "World" << " " << 42;
string result = ss.str();

// Or use reserve() for known size
string str;
str.reserve(100);  // Reserve space
str += "Hello";
str += " World";
```

### 4. Input Validation
```cpp
string input;
cout << "Enter a number: ";
getline(cin, input);

// Validate input
bool isValid = true;
for (char c : input) {
    if (!isdigit(c)) {
        isValid = false;
        break;
    }
}

if (isValid) {
    int num = stoi(input);
    cout << "Valid number: " << num << endl;
} else {
    cout << "Invalid input!" << endl;
}
```

### 5. Memory Management
```cpp
// std::string automatically manages memory
string str = "Hello";
str += " World";  // Memory automatically reallocated

// For C-strings, always ensure null termination
char buffer[100];
strncpy(buffer, "Hello", sizeof(buffer) - 1);
buffer[sizeof(buffer) - 1] = '\0';  // Ensure null termination
```

## Common Pitfalls

### 1. Buffer Overflow
```cpp
// Dangerous - no bounds checking
char buffer[10];
strcpy(buffer, "This is a very long string");  // Buffer overflow!

// Safe - with bounds checking
strncpy(buffer, "This is a very long string", sizeof(buffer) - 1);
buffer[sizeof(buffer) - 1] = '\0';
```

### 2. String Comparison
```cpp
// Wrong - compares pointers, not content
char str1[] = "Hello";
char str2[] = "Hello";
if (str1 == str2) { ... }  // Always false!

// Correct - compares content
if (strcmp(str1, str2) == 0) { ... }  // True
```

### 3. Input Buffer Issues
```cpp
// Problem - cin leaves newline in buffer
int num;
string name;
cin >> num;  // Leaves '\n' in buffer
getline(cin, name);  // Reads empty line

// Solution - clear buffer
cin >> num;
cin.ignore();  // Clear newline
getline(cin, name);
```

This comprehensive guide covers all aspects of character and string handling in C++, from basic concepts to advanced techniques and best practices.

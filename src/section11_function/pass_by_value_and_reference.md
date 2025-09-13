# C++ Pass by Value vs Pass by Reference

## Overview
In C++, there are two main ways to pass parameters to functions: **pass by value** and **pass by reference**. Understanding the difference between these two approaches is crucial for writing efficient and correct C++ programs.

## Pass by Value

### Basic Concept
- A **copy** of the argument is passed to the function
- Changes made to the parameter inside the function do not affect the original variable
- The original variable remains unchanged

### Example
```cpp
#include <iostream>
using namespace std;

// Function that takes parameters by value
void modifyByValue(int x, int y) {
    cout << "Inside function - before modification:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    
    x = 100;  // Modify the copy
    y = 200;  // Modify the copy
    
    cout << "Inside function - after modification:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
}

int main() {
    int a = 10, b = 20;
    
    cout << "Before function call:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    
    modifyByValue(a, b);  // Pass by value
    
    cout << "After function call:" << endl;
    cout << "a = " << a << ", b = " << b << endl;  // Original values unchanged
    
    return 0;
}
```

**Output:**
```
Before function call:
a = 10, b = 20
Inside function - before modification:
x = 10, y = 20
Inside function - after modification:
x = 100, y = 200
After function call:
a = 10, b = 20
```

### Characteristics of Pass by Value
- **Memory**: Creates copies of arguments
- **Performance**: Can be slow for large objects
- **Safety**: Original data is protected from modification
- **Use case**: When you don't want to modify the original data

## Pass by Reference

### Basic Concept
- A **reference** to the original variable is passed to the function
- Changes made to the parameter inside the function directly affect the original variable
- No copying occurs, so it's more efficient

### Example
```cpp
#include <iostream>
using namespace std;

// Function that takes parameters by reference
void modifyByReference(int& x, int& y) {
    cout << "Inside function - before modification:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    
    x = 100;  // Modify the original variable
    y = 200;  // Modify the original variable
    
    cout << "Inside function - after modification:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
}

int main() {
    int a = 10, b = 20;
    
    cout << "Before function call:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    
    modifyByReference(a, b);  // Pass by reference
    
    cout << "After function call:" << endl;
    cout << "a = " << a << ", b = " << b << endl;  // Original values changed
    
    return 0;
}
```

**Output:**
```
Before function call:
a = 10, b = 20
Inside function - before modification:
x = 10, y = 20
Inside function - after modification:
x = 100, y = 200
After function call:
a = 100, b = 200
```

### Characteristics of Pass by Reference
- **Memory**: No copying, uses original memory location
- **Performance**: Fast, no overhead
- **Safety**: Original data can be modified
- **Use case**: When you want to modify the original data or for large objects

## Pass by Const Reference

### Basic Concept
- A **const reference** to the original variable is passed
- Cannot modify the original variable inside the function
- Combines efficiency of pass by reference with safety of pass by value

### Example
```cpp
#include <iostream>
using namespace std;

// Function that takes parameters by const reference
void printValues(const int& x, const int& y) {
    cout << "Values: x = " << x << ", y = " << y << endl;
    
    // x = 100;  // Error! Cannot modify const reference
    // y = 200;  // Error! Cannot modify const reference
}

int main() {
    int a = 10, b = 20;
    
    printValues(a, b);  // Pass by const reference
    
    cout << "Original values unchanged: a = " << a << ", b = " << b << endl;
    
    return 0;
}
```

## Detailed Examples

### Example 1: Swapping Values
```cpp
#include <iostream>
using namespace std;

// Pass by value - DOES NOT work for swapping
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByValue: a = " << a << ", b = " << b << endl;
}

// Pass by reference - WORKS for swapping
void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByReference: a = " << a << ", b = " << b << endl;
}

int main() {
    int x = 10, y = 20;
    
    cout << "Original: x = " << x << ", y = " << y << endl;
    
    // Try pass by value
    swapByValue(x, y);
    cout << "After swapByValue: x = " << x << ", y = " << y << endl;
    
    // Try pass by reference
    swapByReference(x, y);
    cout << "After swapByReference: x = " << x << ", y = " << y << endl;
    
    return 0;
}
```

**Output:**
```
Original: x = 10, y = 20
Inside swapByValue: a = 20, b = 10
After swapByValue: x = 10, y = 20
Inside swapByReference: a = 20, b = 10
After swapByReference: x = 20, y = 10
```

### Example 2: Working with Arrays
```cpp
#include <iostream>
using namespace std;

// Pass array by value (actually passes pointer)
void modifyArrayByValue(int arr[], int size) {
    cout << "Inside function - before modification:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Modify array elements
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
    
    cout << "Inside function - after modification:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Pass array by reference (C++11 style)
void modifyArrayByReference(int (&arr)[5]) {
    cout << "Inside function - before modification:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Modify array elements
    for (int i = 0; i < 5; i++) {
        arr[i] *= 2;
    }
    
    cout << "Inside function - after modification:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    
    cout << "Original array:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    modifyArrayByValue(numbers, 5);
    
    cout << "After modifyArrayByValue:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // Reset array
    int numbers2[] = {1, 2, 3, 4, 5};
    
    modifyArrayByReference(numbers2);
    
    cout << "After modifyArrayByReference:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << numbers2[i] << " ";
    }
    cout << endl;
    
    return 0;
}
```

**Output:**
```
Original array:
1 2 3 4 5
Inside function - before modification:
1 2 3 4 5
Inside function - after modification:
2 4 6 8 10
After modifyArrayByValue:
2 4 6 8 10
Inside function - before modification:
1 2 3 4 5
Inside function - after modification:
2 4 6 8 10
After modifyArrayByReference:
2 4 6 8 10
```

### Example 3: Working with Objects
```cpp
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    
public:
    Person(string n, int a) : name(n), age(a) {}
    
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    string getName() const { return name; }
    int getAge() const { return age; }
    
    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Pass object by value
void modifyPersonByValue(Person p) {
    cout << "Inside function - before modification:" << endl;
    p.display();
    
    p.setName("Modified Name");
    p.setAge(99);
    
    cout << "Inside function - after modification:" << endl;
    p.display();
}

// Pass object by reference
void modifyPersonByReference(Person& p) {
    cout << "Inside function - before modification:" << endl;
    p.display();
    
    p.setName("Modified Name");
    p.setAge(99);
    
    cout << "Inside function - after modification:" << endl;
    p.display();
}

// Pass object by const reference
void displayPerson(const Person& p) {
    cout << "Displaying person (const reference):" << endl;
    p.display();
    // p.setName("New Name");  // Error! Cannot modify const reference
}

int main() {
    Person person("John", 25);
    
    cout << "Original person:" << endl;
    person.display();
    
    cout << "\n--- Pass by Value ---" << endl;
    modifyPersonByValue(person);
    cout << "After modifyPersonByValue:" << endl;
    person.display();
    
    cout << "\n--- Pass by Reference ---" << endl;
    modifyPersonByReference(person);
    cout << "After modifyPersonByReference:" << endl;
    person.display();
    
    cout << "\n--- Pass by Const Reference ---" << endl;
    displayPerson(person);
    
    return 0;
}
```

**Output:**
```
Original person:
Name: John, Age: 25

--- Pass by Value ---
Inside function - before modification:
Name: John, Age: 25
Inside function - after modification:
Name: Modified Name, Age: 99
After modifyPersonByValue:
Name: John, Age: 25

--- Pass by Reference ---
Inside function - before modification:
Name: John, Age: 25
Inside function - after modification:
Name: Modified Name, Age: 99
After modifyPersonByReference:
Name: Modified Name, Age: 99

--- Pass by Const Reference ---
Displaying person (const reference):
Name: Modified Name, Age: 99
```

## Performance Comparison

### Example: Large Object Performance
```cpp
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

class LargeObject {
private:
    vector<int> data;
    
public:
    LargeObject(int size) {
        data.resize(size, 42);
    }
    
    int getSum() const {
        int sum = 0;
        for (int value : data) {
            sum += value;
        }
        return sum;
    }
};

// Pass by value - creates a copy
int processByValue(LargeObject obj) {
    return obj.getSum();
}

// Pass by reference - no copy
int processByReference(const LargeObject& obj) {
    return obj.getSum();
}

int main() {
    const int SIZE = 1000000;
    LargeObject largeObj(SIZE);
    
    // Measure pass by value
    auto start = high_resolution_clock::now();
    int result1 = processByValue(largeObj);
    auto end = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end - start);
    
    // Measure pass by reference
    start = high_resolution_clock::now();
    int result2 = processByReference(largeObj);
    end = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end - start);
    
    cout << "Pass by value result: " << result1 << endl;
    cout << "Pass by value time: " << duration1.count() << " microseconds" << endl;
    
    cout << "Pass by reference result: " << result2 << endl;
    cout << "Pass by reference time: " << duration2.count() << " microseconds" << endl;
    
    return 0;
}
```

## When to Use Each Method

### Use Pass by Value When:
- You want to protect the original data from modification
- The object is small (int, char, double, etc.)
- You need a copy of the data for the function
- The function should not affect the caller's data

### Use Pass by Reference When:
- You want to modify the original data
- The object is large (arrays, strings, custom objects)
- You want to avoid the overhead of copying
- You need to return multiple values

### Use Pass by Const Reference When:
- You want the efficiency of pass by reference
- You don't want to modify the original data
- The object is large
- You want to prevent accidental modifications

## Best Practices

### 1. Prefer Const Reference for Large Objects
```cpp
// Good - efficient and safe
void processData(const vector<int>& data) {
    // Process data without modifying it
}

// Bad - creates unnecessary copy
void processData(vector<int> data) {
    // Process data
}
```

### 2. Use Reference for Output Parameters
```cpp
// Good - clear intent to modify
void getMinMax(const vector<int>& data, int& min, int& max) {
    min = *min_element(data.begin(), data.end());
    max = *max_element(data.begin(), data.end());
}

// Bad - unclear return type
vector<int> getMinMax(const vector<int>& data) {
    // Returns both min and max somehow
}
```

### 3. Use Value for Small, Simple Types
```cpp
// Good - simple and clear
int add(int a, int b) {
    return a + b;
}

// Overkill for simple types
int add(const int& a, const int& b) {
    return a + b;
}
```

### 4. Document Your Intent
```cpp
// Good - clear documentation
void processUserData(const User& user,        // Input: user data
                    bool& success,            // Output: operation success
                    string& errorMessage) {   // Output: error message if failed
    // Implementation
}
```

## Common Pitfalls

### 1. Returning Reference to Local Variable
```cpp
// BAD - returns reference to local variable
int& badFunction() {
    int localVar = 42;
    return localVar;  // Undefined behavior!
}

// GOOD - return by value
int goodFunction() {
    int localVar = 42;
    return localVar;  // Safe
}
```

### 2. Modifying Const Reference
```cpp
void processData(const vector<int>& data) {
    // data.push_back(42);  // Error! Cannot modify const reference
    // data[0] = 100;       // Error! Cannot modify const reference
}
```

### 3. Passing Temporary Objects by Non-Const Reference
```cpp
void modifyValue(int& value) {
    value = 100;
}

int main() {
    // modifyValue(42);  // Error! Cannot bind temporary to non-const reference
    int x = 42;
    modifyValue(x);  // OK
    return 0;
}
```

## Summary

| Aspect | Pass by Value | Pass by Reference | Pass by Const Reference |
|--------|---------------|-------------------|------------------------|
| **Memory** | Creates copy | No copy | No copy |
| **Performance** | Slow for large objects | Fast | Fast |
| **Modification** | Cannot modify original | Can modify original | Cannot modify original |
| **Safety** | High (original protected) | Low (can modify) | High (original protected) |
| **Use Case** | Small objects, need copy | Need to modify, large objects | Large objects, read-only |

Understanding when and how to use each method is essential for writing efficient, safe, and maintainable C++ code.

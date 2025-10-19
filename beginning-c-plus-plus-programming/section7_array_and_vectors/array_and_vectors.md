# C++ Array and Vector Usage

## Array

### Basic Concepts
Array is a fixed-size container in C++ that has its size determined at compile time and cannot be changed dynamically.

### Declaration and Initialization

#### 1. Traditional C-style Array
```cpp
#include <iostream>
using namespace std;

int main() {
    // Declare without initialization
    int arr1[5];
    
    // Declare and initialize
    int arr2[5] = {1, 2, 3, 4, 5};
    
    // Partial initialization (remaining elements are 0)
    int arr3[5] = {1, 2};
    
    // Auto-deduce size
    int arr4[] = {1, 2, 3, 4, 5};
    
    // Zero initialization
    int arr5[5] = {0};
    
    return 0;
}
```

#### 2. std::array (C++11)
```cpp
#include <array>
#include <iostream>

int main() {
    // Declare and initialize
    std::array<int, 5> arr1 = {1, 2, 3, 4, 5};
    
    // Partial initialization
    std::array<int, 5> arr2 = {1, 2};
    
    // Zero initialization
    std::array<int, 5> arr3{};
    
    return 0;
}
```

### Accessing Elements

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    
    // Access using index
    cout << "First element: " << arr[0] << endl;
    cout << "Second element: " << arr[1] << endl;
    
    // Modify elements
    arr[0] = 100;
    cout << "First element after modification: " << arr[0] << endl;
    
    // Using at() method (std::array)
    std::array<int, 5> std_arr = {1, 2, 3, 4, 5};
    cout << "Using at(): " << std_arr.at(2) << endl;
    
    return 0;
}
```

### Iterating Through Array

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    
    // Method 1: Traditional for loop
    cout << "Traditional for loop:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Method 2: Range-based for loop (C++11)
    cout << "Range-based for loop:" << endl;
    for (int element : arr) {
        cout << element << " ";
    }
    cout << endl;
    
    // Method 3: Using std::array
    std::array<int, 5> std_arr = {1, 2, 3, 4, 5};
    cout << "std::array iteration:" << endl;
    for (const auto& element : std_arr) {
        cout << element << " ";
    }
    cout << endl;
    
    return 0;
}
```

### Array Advantages and Disadvantages

**Advantages:**
- Contiguous memory, fast access speed
- Size determined at compile time, high memory efficiency
- Simple and direct

**Disadvantages:**
- Fixed size, cannot change dynamically
- No bounds checking (traditional array)
- Cannot use STL algorithms (traditional array)

---

## Vector

### Basic Concepts
Vector is a dynamic array in C++ STL that can change its size at runtime.

### Declaration and Initialization

```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    // Empty vector
    vector<int> vec1;
    
    // Specify size
    vector<int> vec2(5);
    
    // Specify size and initial value
    vector<int> vec3(5, 10);
    
    // Using initializer list
    vector<int> vec4 = {1, 2, 3, 4, 5};
    
    // Copy from another vector
    vector<int> vec5(vec4);
    
    // Copy from array
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> vec6(arr, arr + 5);
    
    return 0;
}
```

### Common Operations

```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3};
    
    // Add elements
    vec.push_back(4);        // Add at the end
    vec.push_back(5);
    
    // Insert elements
    vec.insert(vec.begin() + 2, 99);  // Insert 99 at index 2
    
    // Remove elements
    vec.pop_back();          // Remove last element
    vec.erase(vec.begin() + 1);  // Remove element at index 1
    
    // Clear
    vec.clear();
    
    // Refill
    vec = {10, 20, 30, 40, 50};
    
    return 0;
}
```

### Accessing and Modifying Elements

```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};
    
    // Access using index
    cout << "First element: " << vec[0] << endl;
    cout << "Second element: " << vec[1] << endl;
    
    // Using at() method (with bounds checking)
    cout << "Using at(): " << vec.at(2) << endl;
    
    // Modify elements
    vec[0] = 100;
    vec.at(1) = 200;
    
    // Access first and last elements
    cout << "First element: " << vec.front() << endl;
    cout << "Last element: " << vec.back() << endl;
    
    return 0;
}
```

### Iterating Through Vector

```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    
    // Method 1: Traditional for loop
    cout << "Traditional for loop:" << endl;
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    
    // Method 2: Range-based for loop
    cout << "Range-based for loop:" << endl;
    for (int element : vec) {
        cout << element << " ";
    }
    cout << endl;
    
    // Method 3: Using iterators
    cout << "Iterators:" << endl;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Method 4: Using const iterators (read-only)
    cout << "Const iterators:" << endl;
    for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}
```

### Common Vector Methods

```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    
    // Size related
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    cout << "Is empty: " << (vec.empty() ? "Yes" : "No") << endl;
    
    // Resize
    vec.resize(10);          // Resize to 10 elements, new elements are 0
    vec.resize(15, 99);      // Resize to 15 elements, new elements are 99
    
    // Reserve space
    vec.reserve(100);        // Reserve space for 100 elements
    
    // Shrink capacity
    vec.shrink_to_fit();
    
    return 0;
}
```

### Two-dimensional Vector

```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    // Declare 2D vector
    vector<vector<int>> matrix(3, vector<int>(4, 0));
    
    // Initialize
    matrix[0] = {1, 2, 3, 4};
    matrix[1] = {5, 6, 7, 8};
    matrix[2] = {9, 10, 11, 12};
    
    // Access elements
    cout << "matrix[1][2] = " << matrix[1][2] << endl;
    
    // Iterate through 2D vector
    cout << "2D vector contents:" << endl;
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

### Vector vs Array Comparison

| Feature | Array | Vector |
|---------|-------|--------|
| Size | Fixed | Dynamic |
| Memory Management | Manual | Automatic |
| Bounds Checking | None (traditional) | Yes (at()) |
| Insert/Delete | Difficult | Easy |
| Performance | Faster | Slightly slower |
| Memory Efficiency | Higher | Slightly lower |
| STL Support | None (traditional) | Full |

### Best Practices

1. **Choose appropriate container**:
   - Fixed size and known → Use `std::array`
   - Need dynamic size → Use `std::vector`

2. **Performance considerations**:
   - Frequent insert/delete → Consider `std::deque` or `std::list`
   - Need fast lookup → Consider `std::set` or `std::unordered_set`

3. **Memory management**:
   - Use `reserve()` to avoid reallocation
   - Use `shrink_to_fit()` to release excess space

4. **Safe access**:
   - Use `at()` for bounds checking
   - Use `empty()` to check if container is empty

```cpp
// Good practice example
#include <vector>
#include <iostream>

int main() {
    vector<int> vec;
    vec.reserve(100);  // Reserve space
    
    for (int i = 0; i < 50; i++) {
        vec.push_back(i);
    }
    
    // Safe access
    if (!vec.empty()) {
        cout << "First element: " << vec.front() << endl;
        cout << "Last element: " << vec.back() << endl;
    }
    
    // Safe access using at()
    try {
        cout << "Element at index 10: " << vec.at(10) << endl;
    } catch (const std::out_of_range& e) {
        cout << "Index out of range!" << endl;
    }
    
    return 0;
}
```

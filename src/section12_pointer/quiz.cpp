#include <iostream>
#include <cstring>
using namespace std;


void swapPointers(int* ptr1, int* ptr2) {
    //-- Write your code below this line
    int temp {*ptr1};
    *ptr1 = *ptr2;
    *ptr2 = temp;
    //-- Write your code above this line
}

void multiply_with_pointer(int* ptr, int multiplier){
    *ptr = (*ptr) * multiplier;
}

int find_max_element(int* arr, int size) {
    //-- Write your code below this line 
    int temp_max {arr[0]};
    for(size_t i{0};i<size;i++ ){
        if(temp_max<*(arr + i)){
            temp_max = *(arr + i);
        }
    }
    return temp_max;
    //-- Write your code below this line 
}

void reverse_array(int* arr, int size) {
    //-- Write your code below this line
    int temp; 
    for(int i{0};i<size/2;i++){
        temp = arr[i];
        arr[i] = *(arr + (size -1 - i));
        arr[size - 1 - i]=temp;
    }
    //-- Write your code above this line
}

std::string reverse_string(const std::string &str) {
    std::string reversed;
    // Write your code below this line 
    const char* start = str.c_str();                    // Pointer to the first character
    const char* end = str.c_str() + str.size() - 1;     // Pointer to the last character

    while (end >= start) {
        reversed.push_back(*end);   // Append the character at the end pointer to the reversed string
        end--;
    }

    // Write your code abocve this line
    return reversed;
}

int main() {
  //quiz 30
  int a {10};
  int b {20};
  swapPointers(&a, &b);
  cout << a << " " << b;
  //quiz 31
  int c {10};
  multiply_with_pointer(&c, 5);
  cout << c;
  //quiz 32
  int arr[] {1,2,3,4,5};
  cout << find_max_element(arr, 5);
  //quiz 33
  int arr2[] {1,2,3,4,5};
  reverse_array(arr2, 5);
  for(int i{0};i<5;i++){
    cout << arr2[i] << " ";
  }
  //quiz 34
  cout << reverse_string("hello");
  return 0;
}
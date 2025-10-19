#include <iostream>

using namespace std;

void say_hi() {
    //--- WRITE YOUR CODE BELOW THIS LINE----  
    std::cout << "Hi Frank!";
    //--- WRITE YOUR CODE ABOVE THIS LINE----
}

void sallys_dogs() {
    
    int x {3};
    
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR CODE BELOW THIS LINE---- 
    cout << "Sally has " << x << " dogs.";
    //---- WRITE YOUR CODE ABOVE THIS LINE----
}

void date_of_birth() {
    int m {2};
    int d {15};
    int y {1993};
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //---- WRITE YOUR CODE BELOW THIS LINE----
    cout << m << " " << d << " " << y;
    //---- WRITE YOUR CODE ABOVE THIS LINE----
    //---- Do NOT MODIFY THE CODE BELOW THIS LINE----
}

int main() {
    say_hi();
    sallys_dogs();
    date_of_birth(); 
    return 0; //The C++ main function must return 0 when the program terminates successfully.
} 
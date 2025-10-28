
#ifndef __DOG_H__
#define __DOG_H__
#include <string>
#include <iostream>

class Dog {
private:
    std::string name;
    int age;
public:
//---- WRITE YOUR NO-ARGS CONSTRUCTOR BELOW THIS LINE----

    Dog() {
        name = "None";
        age = 0;
    }
    Dog(std::string n, int a) {
        name = n;
        age = a;
    }
    Dog (const Dog &d) : name{d.name}, age{d.age} {
        std::cout << "Copy Constructor";
    }
//---- WRITE YOUR NO_ARGS CONSTRUCTOR ABOVE THIS LINE----
//---- DO NOT MODIFY THE CODE BELOW THIS LINE----


    std::string get_name() {return name; }
    void set_name(std::string n) {name = n; }
    int get_age() {return age; }
    void set_age(int a) { age = a;}
    int get_dog_years() { return age * 7; }
    std::string speak() { return "Woof";}

};


#endif 
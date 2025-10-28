#include <string>

// Abstract base class Animal

class Animal {
public:
    virtual std::string get_noise() = 0; // Pure virtual function
    virtual int get_num_legs() = 0; // Pure virtual function
};

class Lion : public Animal {
    public:
        std::string get_noise() override;
        int get_num_legs() override;
    };
    

std::string Lion::get_noise() {
    return "Roar";
}

int Lion::get_num_legs() {
    return 4;
}
    
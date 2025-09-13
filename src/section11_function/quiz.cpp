#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


void c_math_functions() {
    
  double bill_total {102.78};
  int number_of_guests {5};
  
  //DO NOT MODIFY THE CODE ABOVE THIS LINE----
  //----WRITE YOUR CODE BELOW THIS LINE----
  double individual_bill {bill_total/number_of_guests};
  int individual_bill_1 {int(floor(individual_bill))};
  int individual_bill_2 {int(round(individual_bill))};
  double individual_bill_3 {ceil(individual_bill * 100) / 100};
  
  
  //----WRITE YOUR CODE ABOVE THIS LINE----
  //----DO NOT MODIFY THE CODE BELOW THIS LINE----
  cout << "The individual bill at location 1 will be $" << individual_bill_1 << "\n" << "The individual bill at location 2 will be $" << individual_bill_2 << "\n" << "The individual bill at location 3 will be $" << individual_bill_3;
}

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR FUNCTION PROTOTYPES BELOW THIS LINE----
double fahrenheit_to_celsius(double value);
double fahrenheit_to_kelvin(double value);

//----WRITE YOUR FUNCTION PROTOTYPES ABOVE THIS LINE----
//----DO NOT MODIFY THE CODE BELOW THIS LINE----

void temperature_conversion(double fahrenheit_temperature) {
    
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR FUNCTION CALLS BELOW THIS LINE----
    int celsius_temperature = fahrenheit_to_celsius(fahrenheit_temperature);
    int kelvin_temperature = fahrenheit_to_kelvin(fahrenheit_temperature);
    
    
    //----WRITE YOUR FUNCTION CALLS ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    
    cout << "The fahrenheit temperature " << fahrenheit_temperature << " degrees is equivalent to " << celsius_temperature << " degrees celsius and " << kelvin_temperature << " degrees kelvin.";
}

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR FUNCTION DEFINITIONS BELOW THIS LINE----
double fahrenheit_to_celsius(double temperature){
    return round((5.0/9.0)*(temperature - 32));
}
double fahrenheit_to_kelvin(double temperature){
    return round((5.0/9.0)*(temperature - 32) + 273);
}

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR FUNCTION PROTOTYPE BELOW THIS LINE----

void print_grocery_list(int apples =3 , int oranges=7 , int mangos=13);

//----WRITE YOUR FUNCTION PROTOTYPE ABOVE THIS LINE----
//----DO NOT MODIFY THE CODE BELOW THIS LINE----

void modify_grocery_list() {
    
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR FUNCTION CALLS BELOW THIS LINE----
    
    print_grocery_list();
    print_grocery_list(5);
    print_grocery_list(7, 11);


    
    //----WRITE YOUR FUNCTION CALLS ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
}

void print_grocery_list(int apples  , int oranges , int mangos ) { //----WRITE THE FUNCTION PARAMETER LIST WITHIN THE PARENTHESES
                                     //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    cout << apples << " apples" << "\n" << oranges << " oranges" << "\n" << mangos << " mangos" << "\n";
}

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR FUNCTION PROTOTYPES BELOW THIS LINE----

double find_area(double length , double width);
int find_area(int side_length);


//----WRITE YOUR FUNCTION PROTOTYPES ABOVE THIS LINE----
//----DO NOT MODIFY THE CODE BELOW THIS LINE----

void area_calc() {
    
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR FUNCTION CALLS BELOW THIS LINE----
    
    int square_area = find_area(2);
    double rectangle_area = find_area(4.5 ,2.3);
    
    
    //----WRITE YOUR FUNCTION CALLS ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    
    cout << "The area of the square is " << square_area << "\n" << "The area of the rectangle is " << rectangle_area;
}

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR FUNCTION DEFINITIONS BELOW THIS LINE----

double find_area(double length , double width){
    return length*width;
}
int find_area(int side_length){
    return side_length*side_length;
}




int main() {
  //quiz 22
  c_math_functions();
  //quiz 23
  temperature_conversion(32);
  //quiz 24
  modify_grocery_list();
  //quiz 25
  area_calc();
  return 0;
}
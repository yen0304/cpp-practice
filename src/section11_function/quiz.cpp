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

int main() {
  c_math_functions();
  temperature_conversion(32);
  return 0;
}
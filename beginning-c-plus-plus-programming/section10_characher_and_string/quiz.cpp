#include <iostream>
#include <cstring>
using namespace std;

void strings_and_functions() {
    
  //----WRITE YOUR CODE BELOW THIS LINE----
  char first_name[20]= "Bjarne";
  char last_name[20] = "Stroustrup";
  const size_t first_name_length {strlen(first_name)};
  const size_t last_name_length {strlen(last_name)};
  char whole_name[50];
  strcpy(whole_name,first_name);
  strcat(whole_name,last_name);
  const size_t whole_name_length = strlen(whole_name);
  
  //----WRITE YOUR CODE ABOVE THIS LINE----
  //----DO NOT MODIFY THE CODE BELOW THIS LINE----
  
  cout << "The length of the first name, " << first_name << ", is " << first_name_length << " letters long and the length of the last name, " << last_name << ", is " << last_name_length << " letters long. This means that the length of the whole name must be " << whole_name_length << " letters long.";
}

void cpp_strings() {
    
  string unformatted_full_name {"StephenHawking"};
  
  //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
  //----WRITE YOUR CODE BELOW THIS LINE----
  string first_name {unformatted_full_name , 0 , 7};
  string last_name = unformatted_full_name.substr(7,unformatted_full_name.length());
  string formatted_full_name = first_name + last_name;
  
  //----WRITE YOUR CODE ABOVE THIS LINE----
  //----DO NOT MODIFY THE CODE BELOW THIS LINE----
  formatted_full_name.insert(7," ");
  cout << formatted_full_name;
}

void cpp_strings_quiz_21() {
    
  string journal_entry_1 {"Isaac Newton"};
  string journal_entry_2 {"Leibniz"};
  
  //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
  //----WRITE YOUR CODE BELOW THIS LINE----
  journal_entry_1.erase(0,6);
  if(int(journal_entry_1[0]) > int(journal_entry_2[0])){
      swap(journal_entry_1,journal_entry_2);
  }
  
  
  //----WRITE YOUR CODE ABOVE THIS LINE----
  //----DO NOT MODIFY THE CODE BELOW THIS LINE----
  
  cout << journal_entry_1 << "\n" << journal_entry_2;
}

int main() {
  strings_and_functions();
  cpp_strings();
  cpp_strings_quiz_21();
  return 0;
}
#include <iostream>
using namespace std;

void can_you_drive(int age) {
  //----WRITE YOUR CODE BELOW THIS LINE----
  if (age >= 16)
    cout << "Yes - you can drive!";

  //----WRITE YOUR CODE ABOVE THIS LINE----
}

void can_you_drive(int age, bool has_car) {
  //----WRITE YOUR CODE BELOW THIS LINE----
  if (age < 16) {
    cout << "Sorry, come back in " << 16 - age
         << " years and be sure you own a car when you come back.";
  } else if (!has_car) {
    cout << "Sorry, you need to buy a car before you can drive!";
  } else {
    cout << "Yes - you can drive!";
  }
  //----WRITE YOUR CODE ABOVE THIS LINE----
}

void display_day(int day_code) {
  //----WRITE YOUR CODE BELOW THIS LINE----
  switch (day_code) {
  case 0:
    cout << "Sunday";
    break;
  case 1:
    cout << "Monday";
    break;
  case 2:
    cout << "Tuesday";
    break;
  case 3:
    cout << "Wednesday";
    break;
  case 4:
    cout << "Thursday";
    break;
  case 5:
    cout << "Friday";
    break;
  case 6:
    cout << "Saturday";
    break;
  default:
    cout << "Error - illegal day code";
    break;
  }
  //----WRITE YOUR CODE ABOVE THIS LINE----
}

int calculate_sum() {
  //---- WRITE YOUR CODE BELOW THIS LINE
  int sum{0};
  for (int i = 1; i <= 15; i++) {
    if (i % 2 == 1)
      sum += i;
  }
  //---- WRITE YOUR CODE ABOVE THIS LINE
  //---- DO NOT MODIFY THE CODE BELOW
  return sum;
}

int count_divisible() {

  vector<int> vec{1,  3,  5,  15, 16, 17,  18,  19,  20,  21,  25,  26, 27,
                  30, 50, 55, 56, 58, 100, 200, 300, 400, 500, 600, 700};
  //---- WRITE YOUR CODE BELOW THIS LINE----
  int count{0};
  for (auto v : vec) {
    if (v % 3 == 0 || v % 5 == 0) {
      count++;
    }
  }

  //---- WRITE YOUR CODE ABOVE THIS LINE----
  //---- DO NOT CHANGE THE CODE BELOW THIS LINE----
  return count;
}

int count_numbers(const vector<int> &vec) {
    //---- WRITE YOUR CODE BELOW THIS LINE----
    int count {0};
    int i = 0;                
    while (i < vec.size() && vec[i] != -99) {
        count++;
        i++;
    }
    
    //---- WRITE YOUR CODE ABOVE THIS LINE----
    //---- DO NOT MODIFY THE CODE BELOW THIS LINE-----
    return count;
}

void find_first_vowel(const std::vector<char>& vec) {
    //---- WRITE YOUR CODE BELOW THIS LINE----
    const vector<char> vowels {'a','e','i','o','u'};
    bool found {false};
    size_t i = 0;
    if (vec.empty()) {
        cout << "No vowel was found";
        return;
    }
    do {
        char c = vec[i];
        if (find(vowels.begin(), vowels.end(), c) != vowels.end()) {
            cout << "Vowel found: " << c;
            found = true;
        }
        i++;
    } while (i < vec.size() && !found);

    if (!found)
        cout << "No vowel was found";
    //---- WRITE YOUR CODE ABOVE THIS LINE----
}

int calculate_pairs(vector<int> vec) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    if(vec.empty()|| vec.size() == 1){
        return 0;
    }
    int result {0};
    for(int i = 0 ; i < vec.size(); i ++){
        for(int j = i +1 ; j < vec.size(); j ++){
            result += vec[i]*vec[j];
        }
    }
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    return result;
}

int main() {
  can_you_drive(16);
  can_you_drive(15, false);
  display_day(0);
  calculate_sum();
  count_divisible();
  count_numbers({1,2,3,4,5,6,7,8,9,10});
  find_first_vowel({'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'});
  calculate_pairs({1,2,3,4,5,6,7,8,9,10});
  return 0;
}
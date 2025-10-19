#include <vector>
using namespace std;

vector<int> use_array() {
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR CODE BELOW THIS LINE----
    int arr[10]={0};
    arr[0] = 100;
    arr[9] = 1000;
    //-----WRITE YOUR ABOVE THIS LINE----
    //-----DO NOT CHANGE THE CODE BELOW THIS LINE----
    vector<int> v(arr, arr + sizeof arr / sizeof arr[0]);
    return v;
}

vector<int> use_vector() {
    //----WRITE YOUR CODE BELOW THIS LINE----
    vector<int> vec= {10,20,30,40,50}; 
    // vec[0] = 100;
    // vec[vec.size()-1]=1000;
    vec.front() = 100;
    vec.back() = 1000;
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----NO NOT MODIFY THE CODE BELOW THIS LINE----
    return vec;
}

int main() {
    use_array();
    use_vector();
    return 0;
}
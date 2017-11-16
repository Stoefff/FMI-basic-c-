#include <iostream>

using namespace std;

// Task are in the github
int main(){

    unsigned int number;
    unsigned int mask = 1;

    cout << "Enter number ";
    cin >> number;

    cout << "Least significant bit is: " << (number & mask) << endl;
    cout << "Most significant bit is: " << (bool)(number & (mask << 31 )) << endl;


    return 0;
}

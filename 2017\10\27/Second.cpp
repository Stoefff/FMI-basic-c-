#include <iostream>

using namespace std;

int main(){

    unsigned int number, numberPrim;
    unsigned int mask = 1;
    int index1, index2, index3;


    cout << "Enter number: ";
    cin >> number;

    cout << "Enter 3 indexes of bits: " << endl;

    cin >> index1;
    cin >> index2;
    cin >> index3;

    numberPrim = ( ( (number | (mask << index1)) | (mask << index2)) | (mask << index3) );

    cout << "The minus of the numbers: " << numberPrim - number << endl;

    return 0;
}

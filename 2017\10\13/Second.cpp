#include <iostream>

using namespace std;

int main(){

    unsigned int i = 4;
    i = -3;

    cout << "i = " << i << endl;

/*
    cout "i = 4294967293"
    This should be the weird way to turn around Unsigned int's using Signed int

    int i = 4 = 0...0100

    i = -3 = max - 3 ????
*/

    return 0;
}

#include <iostream>

using namespace std;

int main(){

    //Literal : hardcoded value which is not var and usually is precompiled
    // Modulus doesnt work with doubles (can use fmod)

    // Injeneren zapis (sus skrit cast) or
    // 1000000000 = 1x10^8 1e+8
    // 0.00000000 = 1x10^-8 1e-8

    int a = 12;

    int b = 5;

    int c = a / b;

    double d;

    d = a % b;

    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

    char ok = '\\';
    cout << "ok = " << ok << endl;

    return 0;
}
